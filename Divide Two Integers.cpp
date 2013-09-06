class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long a = dividend;
        long long b = divisor;
        if (a == 0) {
            return 0;
        }

        int flag = 1;
        if (a > 0 && b < 0) {
            flag = -1;
        }
        if (a < 0 && b > 0) {
            flag = -1;
        }
        a = abs(a);
        b = abs(b);
        int ret = 0;
        while(a >= b) {
            long long res = 0;
            long long low = 0, high = 32;
            while (low <= high) {
                long long mid = (low + high) >> 1;
                if ((b << mid) <= a) {
                    res = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }   
            }
            a -= (b<<res);
            ret += (1LL << res);
        };
        return ret * flag;
    }
};