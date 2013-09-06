class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int best = 1;
        int st = 0, ed = 0;
        for (int i = 0; i < n; ++i) {
            int len = 0;
            int t = 0;
            for (int j = 0; i - j >= 0 && i + j < n; ++j) {
                if (s[i - j] != s[i + j]) {
                    break;
                } else {
                    t = j;
                }
            }
            len = 2 * t + 1;
            if (len > best) {
                best = len;
                st = i - t;
                ed = i + t;
            }
            t = -1;
            for (int j = 0; i - j >= 0 && i + j + 1 < n; ++j) {
                if (s[i - j] != s[i + j + 1]) {
                    break;
                } else {
                    t = j;
                }
            }
            len = 2 * (t + 1);
            if (len > best) {
                best = len;
                st = i - t;
                ed = i + t + 1;
            }
        }
        return s.substr(st, best);
    }
};