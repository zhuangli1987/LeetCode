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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() == 0) {
            return NULL;
        }
        vector<int> lp;
        vector<int> li;
        vector<int> rp;
        vector<int> ri;
        
        TreeNode * root = new TreeNode(preorder[0]);
        bool flag = true;
        for (int i = 0; i < inorder.size() ; ++i) {
            if (inorder[i] == preorder[0]) {
                flag = false;
                continue;
            }
            if (flag) {
                li.push_back(inorder[i]);
            } else {
                ri.push_back(inorder[i]);
            }
        }
        vector<int> ().swap(inorder);
        for (int i = 1; i < preorder.size() ; ++i) {
            if (lp.size() != li.size()) {
                lp.push_back(preorder[i]);
            } else {
                rp.push_back(preorder[i]);
            }
        }
        vector<int> ().swap(preorder);
        
        root -> left = buildTree(lp, li);
        root -> right = buildTree(rp, ri);
        return root;
    }
};