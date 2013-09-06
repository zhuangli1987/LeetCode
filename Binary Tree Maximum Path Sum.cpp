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
    long long ret;
    int dfs(TreeNode *r) {
        if (r == NULL) {
            return INT_MIN;
        }
        long long ldis = dfs(r -> left);
        long long rdis = dfs(r -> right);
        ret = max(ret, ldis);
        ret = max(ret, rdis);
        ret = max(ret, ldis + r->val);
        ret = max(ret, rdis + r->val);
        ret = max(ret, ldis + rdis + r->val);
        ret = max(ret, (long long)r->val);
        return max((long long)r->val, max(ldis, rdis) + r -> val);
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = INT_MIN;
        dfs(root);
        return ret;
    }
};