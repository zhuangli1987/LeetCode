class Solution {
public:
    string common(string a, string b) {
        if (a.size() > b.size()) {
            swap(a, b);
        }
        string ret;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) {
                ret += a[i];
            } else {
                return ret;
            }
        }
        return ret;
    }
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) {
            return "";
        }
        sort(strs.begin(), strs.end());
        string ret = strs[0];
        for (int i = 1; i <strs.size(); ++i) {
            ret = common(ret, strs[i]);
        }
        return ret;
    }
};