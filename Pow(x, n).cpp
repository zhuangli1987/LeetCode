class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 1.0;
        }
        long long p = n;
        int flag = 1;
        if (p < 0) {
            flag = -1;
        }
        p = abs(p);
        
        double ret = 1.0;
        while (p) {
            if (p & 1) {
                ret = ret * x;
            }
            x = x * x;
            p = p >> 1;
        }
        if (flag == -1) {
            ret = 1.0 / ret;
        }
        return ret;
    }
};