class Solution {
    void dfs(int pos, vector<int> &num, int target, vector<int> &v, vector<vector<int> > &ret, set<vector<int> >&s) {
        if (target == 0) {
            if (s.find(v) == s.end()) {
                ret.push_back(v);
                s.insert(v);
            }
            return;
        }
        if (target < 0) {
            return;
        }
        if (pos == num.size()) {
            return;
        }
        
        v.push_back(num[pos]);
        dfs(pos + 1, num, target - num[pos], v, ret, s);
        v.pop_back();
        dfs(pos + 1, num, target, v, ret, s);
        
        
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         vector<vector<int> > ret;
         vector<int> v;
         set<vector<int> > s;
         sort(num.begin(), num.end());
         dfs(0, num, target, v, ret, s);
         return ret;
    }
};