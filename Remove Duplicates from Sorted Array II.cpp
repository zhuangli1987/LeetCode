class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        
        for (int i = 0; i < n;) {
            int ct = 0;
            for (int j = i + 1; j < n; ++j) {
                if (A[j] == A[i]) {
                    ++ct;
                } else {
                    break;
                }
            }
            if (ct > 1) {
                for (int j = 0; j + i + ct + 1 < n; ++j) {
                    swap(A[i + 2 + j], A[i + ct + 1 + j]);
                }
                ++i;
                n -= (ct - 1);
            }
            ++i;
        }
        return n;
        
    }
};