class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(str == NULL) {
            return 0;
        };
        int ret = 0;
        int flag = 1;
        int i = 0;
        while(str[i] == ' ') {
            ++i;
        }
        if (str[i] == '-') {
            ++i;
            flag = -1;
        }
        if (str[i] == '+') {
            ++i;
        }
        long long now = 0;
        int dg = 10;
        for (; str[i] != '\0' && str[i] != '.'; ++i) {
            if (str[i] > '9' || str[i] < '0') {
                break;
            }
            now = dg * now + str[i] - '0';
        }
        return min(max((long long)INT_MIN, now * flag), (long long)INT_MAX);
    }
};