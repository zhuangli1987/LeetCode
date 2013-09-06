class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = S.size();
        int m = T.size();

        vector<vector<int> > dp;
        dp.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i].resize(m + 1);
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
            dp[i][0] = 1;
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i && j <= m; ++j) {
                dp[i][j] += dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};