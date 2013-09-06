class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = m + n - 1; i >= n; --i) {
            A[i] = A[i - n]; 
        }
        int ia = n;
        int ib = 0;
        int now = 0;
        while (ib < n && ia < m + n) {
            if (B[ib] < A[ia]) {
                A[now] = B[ib];
                ++ib;
            } else {
                A[now] = A[ia];
                A[ia] = INT_MAX;
                ++ia;
            }
            ++now;
        }
        while(ib < n) {
            A[now] = B[ib];
            ++now;
            ++ib;
        }
    }
};