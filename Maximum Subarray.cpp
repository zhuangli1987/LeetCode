class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        int fg = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0) {
                fg = 0;
                break;
            }
        }
        if (fg == -1) {
            int mm = INT_MIN;
            for (int i = 0; i < n; ++i) {
                mm = max(mm, A[i]);
            }
            return mm;
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            ret = max(ret, sum);
            if (sum <= 0) {
                sum = 0;
            }
        }
        return ret;
    }
};