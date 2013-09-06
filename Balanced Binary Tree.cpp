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
    void dfs(TreeNode *rt, map<TreeNode *, int> &m) {
        if (NULL == rt || ! ret) {
            return;
        }
        dfs(rt->left, m);
        dfs(rt->right, m);
        m[rt] = max(m[rt->left], m[rt->right]) + 1;
        if (abs(m[rt->left] - m[rt->right]) > 1) {
            ret = false;
        }
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<TreeNode *, int> m;
        ret = true;
        dfs(root, m);
        return ret;
    }
};