/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(TreeNode *rt, int sum, int now, vector<int> &v) {
        if (!rt -> left && !rt -> right) {
            if (sum == now + rt -> val) {
                v.push_back(rt->val);
                ret.push_back(v);
                v.pop_back();
                return;
            }
        }
        if (rt -> left) {
            v.push_back(rt->val);
            dfs(rt -> left, sum, now + rt -> val, v);
            v.pop_back();
        }
        if (rt -> right) {
            v.push_back(rt->val);
            dfs(rt -> right, sum, now + rt -> val, v);
            v.pop_back();
        }
        
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if (root == NULL) {
            return ret;
        }
        vector<int> v;
        dfs(root, sum, 0, v);
        return ret;
    }
};