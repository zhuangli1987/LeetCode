class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL) {
            return false;
        }
        int n = strlen(s);
        char *x = new char[n + 1];
        strcpy(x, s);
        for (int i = n - 1; x[i] == ' '; --i) {
            x[i] = '\0';
        }
        char *p = x;
        while (*p == ' ') {
            ++p;
        }
        n = strlen(p);
        if (n == 0) {
            delete []x;
            return false;
        }
        int dot = 0;
        int exp = 0;
        int dig = 0;
 
        for (int i = 0; i < n; ++i) {
            if (p[i] >= '0' && p[i] <= '9') {
                ++dig;
                continue;
            }
            if (p[i] == '+' || p[i] == '-') {
                if (i > 0) {
                    if (p[i - 1] == '.') {
                        delete []x;
                        return false;
                    }
                }
                
                if (i != n - 1 && ((p[i + 1] >= '0' && p[i + 1] <= '9') || p[i + 1] == '.')) { 
                    if (i == 0) {
                        continue;
                    }
                    if (p[i - 1] >= '0' && p[i - 1] <= '9') {
                    } else {
                        continue;
                    }
                }
            }
            
            if (p[i] == '.') {
                if (exp == 0) {
                    if (i != n - 1) {
                        if (p[i + 1] == 'e') {
                            if (i > 0) {
                                if (p[i - 1] >= '0' && p[i - 1] <= '9') {
                                } else {
                                    delete []x;
                                    return false;
                                }
                            } else {
                                delete []x;
                                return false;
                            }
                            
                        }
                    }
                    ++dot;
                    continue;
                }
            }
            if (p[i] == 'e') {
                if (i < n - 1 && ((p[i + 1] >= '0' && p[i + 1] <= '9') || p[i + 1] == '+' || p [i + 1] == '-')) {
                    ++exp;
                    continue;
                }
            }
            delete []x;
            return false;
        }
        if (dot > 1 || exp > 1) {
            delete []x;
            return false;
        }
        if (p[n - 1] == 'e' || p[0] == 'e') {
            delete []x;
            return false;
        }
        if (dot == 1 || exp == 1) {
            if (dig == 0) {
                delete []x;
                return false;
            }
        }
        delete []x;
        return true;
    }
};