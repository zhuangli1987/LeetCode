class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        int m = matrix[0].size();
        int zero = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (0 == matrix[i][j]) {
                    zero = i;
                    break;
                }   
            }
            if (zero != -1) {
                break;
            }
        }
        if (zero == -1) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (i == zero) {
                continue;
            }
            int f = 0;
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    f = -1;
                    matrix[zero][j] = 0;
                }
            }
            if (f != 0) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (matrix[zero][i] == 0) {
                for (int j = 0; j < n; ++j) {
                    matrix[j][i] = 0;
                }
            } else {
                matrix[zero][i] = 0;
            }
            
        }
    }
};