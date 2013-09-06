class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long f = x;
        if (f < 0) {
            f = -f;
        }
        int ret = 0;
        while (f) {
            ret = ret * 10 + (f % 10);
            f /= 10;
        }
        return x > 0 ? ret : -ret;
    }
};