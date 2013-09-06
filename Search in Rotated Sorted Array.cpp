class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0, high = n - 1;
        int res = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] >= A[0]) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        low = 0, high = res;
        int ret = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                ret = mid;
                break;
            }
            if (A[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (ret != -1) {
            return ret;
        }
        low = res + 1, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                ret = mid;
                break;
            }
            if (A[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            } 
        }
        return ret;
        
    }
};