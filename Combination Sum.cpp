class Solution {
public:
    void dfs(int pos, vector<int> &candidates, int target, vector<int> &v, vector<vector<int> > &ret) {
        if (target == 0) {
            ret.push_back(v);
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                v.push_back(candidates[i]);
                dfs(i, candidates, target - candidates[i], v, ret);
                v.pop_back();
            }
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        vector<vector<int> > ret;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, v, ret);
        return ret;
    }
};