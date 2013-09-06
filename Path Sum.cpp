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
    bool ret;
    void dfs(TreeNode *rt, int sum, int now) {
        if (ret) {
            return;
        }
        
        if (!rt -> left && !rt -> right) {
            if (sum == now + rt -> val) {
                ret = true;
            }
        }
        if (rt -> left) {
            dfs(rt -> left, sum, now + rt -> val);
        }
        if (rt -> right) {
            dfs(rt -> right, sum, now + rt -> val);
        }
        
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = false;
        if (root == NULL) {
            return false;
        }
        dfs(root, sum, 0);
        return ret;
    }
};