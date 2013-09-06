class Solution {
public:
    void dfs(int r, vector<string> &v, vector<bool> &co, vector<bool> &ed, vector<bool> &es, vector<vector<string> > &ret) {
        if (r == v.size()) {
            ret.push_back(v);
            return;
        }
        
        for (int i = 0; i < v.size(); ++i) {
            if (co[i] == false && ed[i - r +  v.size()] == false && es[i + r] == false) {
                v[r][i] = 'Q';
                co[i] = true;
                ed[i - r +  v.size()] = true;
                es[i + r] = true;
                dfs(r + 1, v , co, ed, es, ret);
                co[i] = false;
                ed[i - r +  v.size()] = false;
                es[i + r] = false;
                v[r][i] = '.';
            }
        }
        
    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        vector<string> v;
        vector<bool> co;
        vector<bool> ed;
        vector<bool> es;
        for (int i = 0; i < 2 * n; ++i) {
            co.push_back(false);
            ed.push_back(false);
            es.push_back(false);
        }
        for (int i = 0; i < n; ++i) {
            string s = "";
            for (int j = 0; j < n; ++j) {
                s += '.';
            }
            v.push_back(s);
        }
        dfs(0, v, co, ed, es, ret);
        return ret;
    }
};