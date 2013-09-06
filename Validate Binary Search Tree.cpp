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
    vector <int> x;
    void dfs(TreeNode *rt) {
        if (rt == NULL) {
            return;
        }
        dfs(rt -> left);
        x.push_back(rt -> val);
        dfs(rt -> right);
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        x.clear();
        dfs(root);
        for (int i = 1; i < x.size(); ++i) {
            if (x[i] <= x[i - 1]) {
                return false;
            }
        }
        return true;
    }
};