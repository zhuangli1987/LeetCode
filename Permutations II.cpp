class Solution {
public:
    vector<vector<int> > ret;
    set<vector<int> > ss;
    void dfs(int pos, int n, vector<int> x) {
        if (pos == n) {
            ss.insert(x);
            return;
        }
        for (int i = pos; i < n; ++i) {
            swap(x[i], x[pos]);
            dfs(pos + 1, n, x);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        ss.clear();
        dfs(0, num.size(), num);
        for (set<vector<int> >::iterator it = ss.begin(); it != ss.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
}; 
