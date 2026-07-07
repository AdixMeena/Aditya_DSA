class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string xStr = "";
        int sum = 0;

        for (char c : s)
        {
            if (c != '0')
            {
                xStr += c;            
                sum += (c - '0');     
            }
        }

        long long x = xStr.empty() ? 0 : stoll(xStr); 

        return x * sum;
    }
};