class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> dp;
        dp.resize(n);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && A[i] < A[i - 1]) {
                continue;
            }
            if (dp[i]) {
                for (int j = 1; j <= A[i] && i + j < n; ++j) {
                    dp[i + j] = true;
                }
            }
        }
        return dp[n - 1];
    }
};