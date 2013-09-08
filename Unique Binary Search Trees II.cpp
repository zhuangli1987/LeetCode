/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode *> dfs(int st, int ed) {
    vector<TreeNode *> ret;
    if (st >= ed) {
        ret.push_back(NULL);
        return ret;
    }
    for (int i = st; i < ed; ++i) {
        vector<TreeNode *> ll = dfs(st, i);
        vector<TreeNode *> rr = dfs(i + 1, ed);
        for (int j = 0; j < ll.size(); ++j) {
            for (int k = 0; k < rr.size(); ++k) {
                TreeNode * root = new TreeNode(i + 1);
                root -> left = ll[j];
                root -> right = rr[k];
                ret.push_back(root);
            }
        }
    }
    return ret;
}

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(0, n);
    }
};