class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0, high = n - 1;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] >= target) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        vector<int> ret;
        if (A[res] != target) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        ret.push_back(res);
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] <= target) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }   
        }
        ret.push_back(res);
    }
};