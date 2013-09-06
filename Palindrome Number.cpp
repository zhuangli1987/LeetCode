class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) {
            return false;
        }
        long long n = x;
        long long ret = 0;
        while (x) {
            ret = 10 * ret + x % 10;
            x = x / 10;
        }
        return ret == n;
        
    }
};