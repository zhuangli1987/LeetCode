class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[low] < A[mid]) {
                if (target >= A[low] && target < A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                
            } else if (A[low] > A[mid]) {
                if (target <= A[high] && target > A[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                ++low;
            }
        }
        return false;
        
    }
};