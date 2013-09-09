class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int st = 0, ed = n - 1;
        for (int i = 0; i < n; ++i) {
            if (A[i] != 0) {
                st = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (A[i] != 0) {
                ed = i;
                break;
            }
        }
        ++ed;
        int ret = 0;
        for (int i = st; i < ed;) {
            int next = i + 1;
            for (int j = next; j < ed; ++j) {
                if (A[j] >= A[i]) {
                    next = j;
                    break;
                }
            }
            for (int j = i; j < next; ++j) {
                if (A[j] < A[i]) {
                    ret += A[i] - A[j];
                    A[j] = A[i];
                }
            }
            i = next;
        }
        reverse(A + st, A + ed);
        for (int i = st; i < ed;) {
            int next = i + 1;
            for (int j = next; j < ed; ++j) {
                if (A[j] >= A[i]) {
                    next = j;
                    break;
                }
            }
            for (int j = i; j < next; ++j) {
                if (A[j] < A[i]) {
                    ret += A[i] - A[j];
                    A[j] = A[i];
                }
            }
            i = next;
        }
        return ret;
    }
};