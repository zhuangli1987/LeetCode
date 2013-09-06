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
        if (rt == NULL) {
            return;
        }
        if (rt -> left == NULL && rt -> right == NULL) {
            ret = max(ret, dp);
            return;
        }
        dfs(rt -> left, dp + 1);
        dfs(rt -> right, dp + 1);
    }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = -1;
        dfs(root, 0);
        return ret + 1;
    }
};