class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int hash[256];
        memset(hash, 0, sizeof(hash));
        int ret = 0;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (!hash[ch]) {
                ++len;
                ++hash[ch];
            } else {
                for (int j = i - len; j < i; ++j) {
                    --hash[s[j]];
                    --len;
                    if (ch == s[j]) {
                        break;
                    }
                }
                ++hash[ch];
                ++len;
            }
            ret = max(ret, len);
        }
        return ret;
    }
};