class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x[2] = {1, 1};
        for (int i = 2; i <= n; ++i) {
            int now = x[0] + x[1];
            x[0] = x[1];
            x[1] = now;
        } 
        return x[1];
    }
};