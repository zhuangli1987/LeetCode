class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp;
        dp.resize(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1) {
                if (s[i - 2] != '0') {
                    int x = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
                    if (x <= 26 && x >= 1) {
                        dp[i] += dp[i - 2];
                    }
                    
                }
            }
        }
        return dp[n];
    }
};