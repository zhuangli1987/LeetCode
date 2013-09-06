class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        int ret = 0;
        vector< vector<int> > lsum;
        vector< vector<int> > rsum;
        lsum.resize(n);
        rsum.resize(n);
        for (int i = 0; i < n; ++i) {
            lsum[i].resize(m);
            rsum[i].resize(m);
            for (int j = 0; j < m; ++j) {
                lsum[i][j] = 0;
                for (int k = 1; j + k < m; ++k) {
                    if (matrix[i][j + k] == '1') {
                        ++rsum[i][j];
                    }  else {
                        break;
                    }
                }
                for (int k = 1; j - k >= 0; ++k) {
                    if (matrix[i][j - k] == '1') {
                        ++lsum[i][j];
                    }  else {
                         break;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int ll = INT_MAX;
                int rr = INT_MAX;
                for (int k = 0; i + k < n; ++k) {
                    if (matrix[k + i][j] == '0') {
                        break;
                    }
                    ll = min(ll, lsum[k + i][j]);
                    rr = min(rr, rsum[k + i][j]);
                    int now = ll + rr + 1;
                    ret = max(now * (k + 1), ret);
                }
            }
        
        }
        return ret;
    }
};