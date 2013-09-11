bool equal(char a, char b) {
    return a == '*' || b == '*' || a == '?' ||  b == '?' || a == b;
}

struct Pattern {
    vector<string> tokens;
    Pattern (string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                s[i] = ' ';
            }
        }
        stringstream in(s);
        string token;
        while (in >> token) {
            tokens.push_back(token);
        } 
        
    }
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string a = s;
        string b = p;
        int n = a.size();
        int m = b.size();
        
        int prefix = 0, suffix = 0;
        
        while (prefix < m && b[prefix] != '*') {
            if (prefix == n || !equal(a[prefix], b[prefix])) {
                return false;
            }
            ++prefix;
        }
        
        while (prefix <= m - 1 - suffix && b[m - 1 - suffix] != '*') {
            if (prefix > n - suffix - 1 || !equal(a[n - 1 - suffix], b[m - 1 - suffix])) {
                return false;
            }
            ++suffix;
        }
        a = a.substr(prefix, n - prefix - suffix);
        b = b.substr(prefix, m - prefix - suffix);
        
        if (b.size() == 0) {
            return a.size() == 0;
        }
        
        Pattern pattern = Pattern(b);
        int cur = 0;
        for (int i = 0; i < pattern.tokens.size(); ++i) {
            string token = pattern.tokens[i];
            bool found = false;
            for (; cur + token.size() <= a.size() && !found; ++cur) {
                found = true;
                for (int j = 0; j < token.size(); ++j) {
                    if (!equal(a[cur + j], token[j])) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    cur += token.size();
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
        
    }
};