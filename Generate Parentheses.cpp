class Solution {
public:
    vector<string> ret;
    void dfs(int pos, int max, int val, string now) {
        if (val < 0 || val > max) {
            return;
        }
        if (pos == 2 * max) {
            if (val == 0) {
                ret.push_back(now);
            }
            return;
        }
        dfs(pos + 1, max, val + 1, now + "(");
        dfs(pos + 1, max, val - 1 , now + ")");
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        dfs(0, n, 0, "");
        return ret;
    }
};