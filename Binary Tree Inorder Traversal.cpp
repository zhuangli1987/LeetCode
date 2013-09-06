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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        stack<TreeNode *> s;
        while (!s.empty() || root != NULL) {
            while (root != NULL) {
                s.push(root);
                root = root -> left;
            }
            if (!s.empty()) {
                root = s.top();
                ret.push_back(root -> val);
                s.pop();
                root = root -> right;
            }
        }
        return ret;
    }
};