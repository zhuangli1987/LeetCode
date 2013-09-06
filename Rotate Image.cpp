class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i + 1; j < n - i - 1; ++j) {
                swap(matrix[i][j], matrix[n - j - 1][i]);
                swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
                swap(matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]);
            }
            swap(matrix[i][i], matrix[n - i - 1][i]);
            swap(matrix[n - i - 1][i], matrix[n - i - 1][n - i - 1]);
            swap(matrix[n - i - 1][n - i - 1], matrix[i][n - i - 1]);
        }
    }
};