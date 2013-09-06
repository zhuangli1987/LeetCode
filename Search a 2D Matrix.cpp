class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int low = 0, high = m -1;
        int r = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target) {
                r = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (r == -1) {
            return false;
        }
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[r][mid] == target) {
                return true;
            }
            if (matrix[r][mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
        
    }
};