class Solution {
public:
    void dfs(int pos, vector< vector<bool> > &mat, vector<vector<string> > &ret, vector<int> &v, string &s) {
        if (pos == -1) {
            vector<string> e;
            reverse(v.begin(), v.end());
            for (int i = 0; i < v.size() - 1; ++i) {
                string t = "";
                for (int j = v[i]; j < v[i + 1]; ++j) {
                    t += s[j];
                }
                e.push_back(t);
            }
            reverse(v.begin(), v.end());
            ret.push_back(e);
            return;
        }
        for (int i = 0; i <= pos; ++i) {
            if (mat[i][pos]) {
                v.push_back(i);
                dfs(i - 1, mat, ret, v, s);
                v.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        int n = s.size();
        vector< vector<bool> > mat;
        mat.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            mat[i].resize(n + 1);
            for (int j = 0; j < n; ++j) {
                mat[i][j] = false;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int k = i, j = i; k >= 0 && j < n; --k, ++j) {
                if (s[k] == s[j]) {
                    mat[k][j] = true;
                } else {
                    break;
                }
            }
            for (int k = i, j = i + 1; k >= 0 && j < n; --k, ++j) {
                if (s[k] == s[j]) {
                    mat[k][j] = true;
                } else {
                    break;
                }
            }
        }
        vector<int> v;
        v.push_back(s.size());
        dfs(n - 1, mat, ret, v, s);
        return ret;
        
        
    }
};