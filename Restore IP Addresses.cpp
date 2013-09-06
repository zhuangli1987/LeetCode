class Solution {
public:
    vector<string> ret;
    void dfs(string &s, int pos, int seg, int v, string now) {
        if (v > 255) {
            return;
        }
        if (pos == s.size()) {
            if (seg == 3) {
                ret.push_back(now);
            }
            return;
        }
        if (now.size() > 0 && now[now.size() - 1] == '0' && v == 0) {
        } else {
            v = 10 * v + s[pos] - '0';
            dfs(s, pos + 1, seg, v, now + s[pos]);
        }
        v = s[pos] - '0';
        if (now != "") {
            dfs(s, pos + 1, seg + 1, v, now + "." + s[pos]);
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if (s.size() > 13) {
            return ret;
        }
        dfs(s, 0, 0, 0, "");
        return ret;
    }
};