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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        if (n == 0) {
            return NULL;
        }
        vector<int> a;
        vector<int> b;
        TreeNode *root =  new TreeNode(0);
        for (int i = 0; i < n; ++i) {
            if (i < n / 2) {
                a.push_back(num[i]);
            } else if (i == n / 2) {
                root -> val = num[i];
            } else {
                b.push_back(num[i]);
            }
        }
        root -> left = sortedArrayToBST(a);
        root -> right = sortedArrayToBST(b);
        return root;
    }
};