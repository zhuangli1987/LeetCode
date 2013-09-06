class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) {
            return ret;
        }
        int n = matrix[0].size();
        ret.resize(n * m);
        vector< vector<bool> > dp;
        dp.resize(m);
        for (int i = 0; i < m; ++i) {
            dp[i].resize(n);
            for (int j = 0; j < n; ++j) {
                dp[i][j] = false;
            }
        }
        int i = 0, j = 0, now = 0;
        int d = 0;
        while (now  < n * m) {
            if (i < 0 || j < 0 || i >= m || j >= n || dp[i][j]) {
                i = i - dx[d];
                j = j - dy[d];
                d = d + 1;
                d = d % 4;
            } else {
                ret[now ++] = matrix[i][j];
                dp[i][j] = true;
            }
            i += dx[d];
            j += dy[d];
        }
        return ret;        
    }
};