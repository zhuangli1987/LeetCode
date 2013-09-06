class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int det = x / 2 + 1;
        int low = 0, high = det;
        int ret = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid * mid <= x) {
                ret = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ret;
    }
};