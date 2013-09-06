class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0, high = n - 1;
        int ret = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] <= target) {
                low = mid + 1;
                ret = mid;
            } else {
                high = mid - 1;
            }
        }
        if (A[ret] >= target) {
            return ret;
        }
        return ret + 1;
    }
};