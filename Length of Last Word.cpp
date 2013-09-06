class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strlen(s);
        int ret = 0;
        int i = n - 1;
        for (;i >= 0;--i) {
            if (s[i] == ' ') {
                continue;
            } else {
                break;
            }
        }
        for (; ; --i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ++ret;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                ++ret;
            } else {
                break;
            }
        }
        return ret;
        
    }
};