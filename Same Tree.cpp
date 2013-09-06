/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void dfs1(TreeNode *rt, vector<int> &v) {
    if (rt == NULL) {
        v.push_back(-1);
        return;
    }
    v.push_back(rt -> val);
    dfs1(rt -> left, v);
    dfs1(rt -> right, v);
}

void dfs2(TreeNode *rt, vector<int> &v) {
    if (rt == NULL) {
        v.push_back(-1);
        return;
    }
    dfs2(rt -> left, v);
    v.push_back(rt -> val);
    dfs2(rt -> right, v);
}
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> p1, p2, m1, m2;
        dfs1(p, p1);
        dfs1(q, p2);
        dfs2(p, m1);
        dfs2(q, m2);
        return p1 == p2 && m1 == m2;
    }
};