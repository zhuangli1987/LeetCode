class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int pos, int n, vector<int> x) {
        if (pos == n) {
            ret.push_back(x);
            return;
        }
        for (int i = pos; i < n; ++i) {
            swap(x[i], x[pos]);
            dfs(pos + 1, n, x);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        dfs(0, num.size(), num);
        return ret;
    }
};