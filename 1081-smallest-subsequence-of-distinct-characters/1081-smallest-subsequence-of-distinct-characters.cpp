class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_occurrence(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i] - 'a'] = i;
        }
        
        string stack;
        vector<bool> seen(26, false);
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (seen[c - 'a']) continue;
            
            while (!stack.empty() && stack.back() > c && 
                   last_occurrence[stack.back() - 'a'] > i) {
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            stack.push_back(c);
            seen[c - 'a'] = true;
        }
        
        return stack;
    }
};