class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x = 1;
        for (int i = 1; i <= n; ++i) {
            x = x * (4 * i - 2) / (i + 1);
        }
        return x;
    }
};