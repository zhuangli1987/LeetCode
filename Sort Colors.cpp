class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = 0, w = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                ++r;
            } else if (A[i] == 1) {
                ++w;
            } else {
                ++b;
            }
        }
        for (int i = 0; i < r; ++i) {
            A[i] = 0;
        }
        for (int i = r; i < r + w; ++i) {
            A[i] = 1;
        }
        for (int i = r + w; i < n; ++i) {
            A[i] = 2;
        }
    }
};