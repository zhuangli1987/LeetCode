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
    int ret;
    void dfs(TreeNode *rt, int dp) {
        if (rt == NULL || dp > ret) {
            return;
        }
        if (rt -> left == NULL && rt -> right == NULL) {
            ret = min(dp, ret);
        }
        dfs(rt -> left, dp + 1);
        dfs(rt -> right, dp + 1);
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = INT_MAX;
        dfs(root, 0);
        if (ret == INT_MAX) {
            ret = 0;
        } else {
            ++ret;
        }
        
        return ret;
    }
};