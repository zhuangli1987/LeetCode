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
    void dfs(TreeNode *root, TreeNode * &pre, TreeNode * &n1, TreeNode * &n2) {
        if (root == NULL) {
            return;
        }
        dfs(root -> left, pre, n1, n2);
        if (pre != NULL && pre -> val > root -> val) {
            n1 = root;
            if (n2 == NULL) {
                n2 = pre;
            }
        }
        pre = root;
        
        dfs(root -> right, pre, n1, n2);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *pre = NULL, *n1 = NULL, *n2 = NULL;
        dfs(root, pre, n1, n2);
        if (n1 != NULL && n2 != NULL) {
            swap(n1 -> val, n2 -> val);
        }
    }
};