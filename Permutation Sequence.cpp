class Solution {
public:
    map<int, vector<string> > ans;
    void dfs(int pos, int n, string res) {
        if (pos == n) {
            ans[n].push_back(res);
            return;
        }
        for (int i = pos; i < n; ++i) {
            swap(res[i], res[pos]);
            dfs(pos + 1, n, res);
            //swap(res[i], res[pos]);
        }
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (ans.find(n) != ans.end()) {
            return ans[n][k - 1];
        }
        string ret = "";
        for (int i = 1; i <= n; ++i) {
            char t[2];
            t[1] = '\0';
            t[0] = i + '0';
            ret += t;
        }
        dfs(0, n, ret);
        return ans[n][k - 1];;
    }
};