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
    bool dfs(TreeNode *l, TreeNode *r) {
        if (l == NULL && r == NULL) {
            return true;
        }
        if (l && r) {
            if (l -> val != r -> val) {
                return false;
            }
            return dfs(l -> left, r -> right) && dfs(l -> right, r -> left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(root, root);
    }
};