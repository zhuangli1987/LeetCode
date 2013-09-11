struct String {
    vector< pair<char, bool> > v;
    String(const char *s) {
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] == '*') {
                v[v.size() - 1].second = true;
            } else {
                v.push_back(make_pair(s[i], false));
            }
        }
    }
    bool stay(int i) {
        return v[i].second;
    }
    char get(int i) {
        return v[i].first;
    }
    int size() {
        return v.size();
    }
};

bool equal(char a, char b) {
    return a == b || a == '.' || b == '.';
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        String a = String(s);
        String b = String(p);
        vector< vector<bool> > dp;
        dp.resize(a.size() + 2);
        for (int i = 0; i <= a.size(); ++i) {
            dp[i].resize(b.size() + 2);
        }
        dp[0][0] = true;
        for (int i = 0; i <= a.size(); ++i) {
            for (int j = 0; j <= b.size(); ++j) {
                if (dp[i][j]) {
                    // skip
                    if (j < b.size() && b.stay(j)) {
                        dp[i][j + 1] = true;
                    }
                    
                    // just match
                    if (i < a.size() && j < b.size() && equal(a.get(i), b.get(j)) ) {
                        dp[i + 1][j + 1] = true;
                        if (b.stay(j)) {
                            dp[i + 1][j] = true;
                        }
                    }
                }
                
            }
        }
        return dp[a.size()][b.size()];   
    }
};