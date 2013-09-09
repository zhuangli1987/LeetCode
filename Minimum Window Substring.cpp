class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hash[256];
        for (int i = 0; i < 256; ++i) {
            hash[i] = INT_MAX;
        }
        int ct = 0;
        for (int i = 0; i < T.size(); ++i) {
            if (hash[T[i]] == INT_MAX) {
                hash[T[i]] = 0;
                ++ct;
            }
            ++hash[T[i]];
        }
        
        int st = 0, ed = 0;
        int x = 0, y = - 1;
        int now = 0;
        int ret = S.size() + 1;
        string bk = "";
        while (ed < S.size()) {
            if (hash[S[ed]] == INT_MAX) {
                ++ed;
                continue;
            }
            --hash[S[ed]];
            if (hash[S[ed]] == 0) {
                ++now;
            }
            if (now == ct) {
                //
                for (int i = st; i <= ed; ++i) {
                    if (hash[S[i]] == INT_MAX) {
                        ++st;
                        continue;
                    }
                    if (hash[S[i]] < 0) {
                        ++hash[S[i]];
                        ++st;
                    } else if (hash[S[i]] >= 0) {
                        break;
                    }
                }
                if (ed - st + 1 < ret) {
                    ret = ed - st + 1;
                    x = st;
                    y = ed;
                }
            }
            ++ed;
        }
        for (int i = x; i <= y; ++i) {
            bk += S[i];
        }
        return bk;
    }
};