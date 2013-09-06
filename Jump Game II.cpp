class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp;
        dp.resize(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && A[i] < A[i - 1]) {
                continue;
            }
            for (int j = 1; j <= A[i] && j + i < n; ++j) {
                dp[j + i] = min(dp[j + i], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
};