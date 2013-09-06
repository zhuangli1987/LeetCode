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
TreeNode *p;
void dfs(TreeNode *rt) {
    if (rt == NULL) {
        return;
    }
    swap(rt -> left, rt -> right);
    
    if (rt -> right == NULL) {
        p = rt;
    }
    
    dfs(rt -> right);

    if (rt -> left) {
        p -> right = rt -> left;
        dfs(rt -> left);
        rt -> left = NULL;
    }
}
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        p = NULL;
        dfs(root);
    }
};