class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int m = edges.size();

        vector<array<long long,3>> usable;
        usable.reserve(m);
        vector<long long> costs;
        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            if (online[u] && online[v]) {
                usable.push_back({u, v, c});
                costs.push_back(c);
            }
        }
        if (usable.empty()) return -1;

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        vector<vector<pair<int,long long>>> g(n);
        for (auto &e : usable) g[e[0]].push_back({(int)e[1], e[2]});

        vector<int> indeg(n, 0);
        for (auto &e : usable) indeg[e[1]]++;
        vector<int> topo;
        topo.reserve(n);
        {
            vector<int> deg = indeg;
            queue<int> q;
            for (int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
            vector<vector<int>> tmpAdj(n);
            for (auto &e : usable) tmpAdj[e[0]].push_back(e[1]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                topo.push_back(u);
                for (int v : tmpAdj[u]) if (--deg[v] == 0) q.push(v);
            }
        }

        const long long INF = LLONG_MAX / 2;

        auto feasible = [&](long long s) -> bool {
            vector<long long> dist(n, INF);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == INF) continue;
                for (auto &[v, c] : g[u]) {
                    if (c < s) continue;
                    if (dist[u] + c < dist[v]) dist[v] = dist[u] + c;
                }
            }
            return dist[n-1] <= k;
        };

        int lo = 0, hi = (int)costs.size() - 1, best = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(costs[mid])) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return best == -1 ? -1 : (int)costs[best];
    }
};