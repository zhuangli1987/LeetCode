class Solution {
public:
    void dfs(int pos, vector<int> &v, vector<vector<int> > &ret, int n, int k) {
        if (v.size() == k) {
            ret.push_back(v);
        }
        for (int i = pos; i <= n; ++i) {
            v.push_back(i);
            dfs(i + 1, v, ret, n, k);
            v.pop_back();
        }
        
    } 
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
            dfs(i + 1, v, ret, n, k);
            v.pop_back();
        }
        return ret;
    }
};