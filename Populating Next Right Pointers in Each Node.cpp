/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        struct node {
            TreeLinkNode *rt;
            int level;
        };
        if (root == NULL) {
            return;
        }
        node st;
        st.rt = root;
        st.level = 0;
        queue<node> q;
        q.push(st);
        TreeLinkNode *pre = root;
        int level = -1;
        while (!q.empty()) {
            node t = q.front();
            q.pop();
            if (t.rt == NULL) {
                continue;
            }
            t.rt -> next = NULL;
            if (level !=  t.level) {
                level = t.level;
            } else {
                pre -> next = t.rt;
            }
            
            node n;
            n.rt = t.rt -> left;
            n.level = t.level + 1;
            q.push(n);

            n.rt = t.rt -> right;
            n.level =  t.level + 1;
            q.push(n);

            pre = t.rt;
        }
        pre -> next = NULL;
    }
};