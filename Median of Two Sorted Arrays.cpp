class Solution {
public:
    bool check(int x, int A[], int m, int B[], int n, int k) {
        return x >= k || (k - x - 1 < n && B[k - x - 1] <= A[x]);
    }
    double findArray(int A[], int m, int B[], int n, int k) {
        int low = 0, high = m - 1;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, A, m , B, n, k)) {
                high = mid - 1;
                res = mid;
            } else {
                low = mid + 1;
            }
        }
        if (res == -1) {
            return INT_MAX;
        }
        return A[res];
    }
    double findLeastK(int A[], int m, int B[], int n, int k) {
        return min(findArray(A, m, B, n, k), findArray(B, n, A, m, k));
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = m + n;
        int cnt = 1;
        int k = total / 2;
        double res = findLeastK(A, m, B, n, k);
        if (total % 2 == 0) {
            res += findLeastK(A, m, B, n, k - 1);
            ++cnt;
        }
        return res / cnt;
    }
};