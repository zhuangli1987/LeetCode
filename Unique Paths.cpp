class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > dp;
        dp.resize(m);
        for (int i = 0; i < dp.size(); ++i) {
            dp[i].resize(n);
        }
        dp[0][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    dp[i][j] += dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
                
            }
        }
        return dp[m - 1][n - 1];
    }
};