class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (needle == NULL || haystack == NULL) {
            return NULL;
        }
        int n = strlen(haystack);
        int m = strlen(needle);
        if (m == 0) {
            return haystack;
        }
        
        if (n < m) {
            return NULL;
        }
        for (int i = 0; i < n - m + 1; ++i) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return haystack + i;
            }
        }
        return NULL;;
    }
};