class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector< vector<int> > dp;
        dp.resize(m);
        for (int i = 0; i < dp.size(); ++i) {
            dp[i].resize(n);
        }
        if (obstacleGrid[0][0]) {
            dp[0][0] = 0;
        } else {
            dp[0][0] = 1;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
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