class Solution {
public:
    void dfs(int pos, vector<bool> &co, vector<bool> &ed, vector<bool> &es, int n, int &ret) {
        if (pos == n) {
            ++ret;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!co[i] && !ed[i - pos + n] && !es[i + pos]) {
                co[i] = true;
                ed[i - pos + n] = true;
                es[i + pos] = true;
                dfs(pos + 1, co, ed, es, n, ret);
                co[i] = false;
                ed[i - pos + n] = false;
                es[i + pos] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> co, ed, es;
        for (int i = 0; i < 2 * n; ++i) {
            co.push_back(false);
            ed.push_back(false);
            es.push_back(false);
        }
        
        int ret = 0;
        dfs(0, co, ed, es, n, ret);
        return ret;
    }
};