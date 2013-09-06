class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector < vector<int> > dp;
        int n = word1.size();
        int m = word2.size();
        dp.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i].resize(m + 1);
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = INT_MAX;
                if (i == 0) {
                    dp[i][j] = j;
                }
            }
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
                }
            }
        }
        return dp[n][m];
    }
};