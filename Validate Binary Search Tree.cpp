/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode *root, int min, int max) {
    if (root) {
        if (root -> val <= min || root -> val >= max) {
            return false;
        }
        return dfs(root -> left, min, root -> val) && dfs(root -> right, root -> val, max);
    }
    return true;
}
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(root, INT_MIN, INT_MAX);
    }
};