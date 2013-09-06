class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; ++i) {
            int x = A[i] - 1;
            if (x < 0 || x >= n || A[x] == A[i]) {
                continue;
            }
            swap(A[x], A[i]);
            --i;
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
        
    }
};