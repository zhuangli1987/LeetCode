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
    void dfs(TreeNode *rt, int now) {
        if (rt -> left == NULL && rt -> right == NULL) {
            ret += now;
            return;
        }
        if (rt -> left) {
            dfs(rt -> left, now  * 10 + rt -> left -> val);
        }
        if (rt -> right) {
            dfs(rt -> right, now * 10 + rt -> right -> val);
        }
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        if (root) {
            dfs(root, root -> val);
        }
        return ret;
    }
};