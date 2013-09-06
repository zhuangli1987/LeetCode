class Solution {
public:
    set< vector<int> > s;
    vector<vector<int> > ret;
    void dfs(vector<int> &S, int pos, vector<int> v) {
        if (pos < S.size()) {
            dfs(S, pos + 1, v);
            v.push_back(S[pos]);
            dfs(S, pos + 1, v);
        } else {
            s.insert(v);
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        s.clear();
        ret.clear();
        vector<int> x;
        dfs(S, 0, x);
        for (set< vector<int> >::iterator it = s.begin(); it != s.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
};