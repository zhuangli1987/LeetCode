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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > ret;
        struct node {
            TreeNode * rt;
            int level;
        };
        queue<node> q;
        node rt;
        rt.rt = root;
        rt.level = 0;
        q.push(rt);
        vector<int> t;
        while (!q.empty()) {
            node n = q.front();
            q.pop();
            if (n.rt == NULL) {
                continue;
            }
            if (n.level > ret.size()) {
                ret.push_back(t);
                t.clear();
            }
            t.push_back(n.rt -> val);
            node x;
            x.level = n.level + 1;
            x.rt = n.rt -> left;
            q.push(x);
            x.rt = n.rt -> right;
            q.push(x);
            
        }
        if (t.size() > 0) {
            ret.push_back(t);
        }
        return ret;
    }
};