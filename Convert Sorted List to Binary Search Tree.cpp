/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        int n = 0;
        ListNode *p = head;
        while (p) {
            ++n;
            p = p -> next;
        }
        ListNode * a = new ListNode(-1);
        ListNode * b = new ListNode(-1);
        ListNode * p1 = a;
        ListNode * p2 = b;
        p = head;
        int mid = n / 2;
        TreeNode * root = new TreeNode(0);
        for (int i = 0; i < n; ++i) {
            if (i == mid) {
                root -> val = p -> val;
            } else if (i < mid) {
                p1 -> next = p;
                p1 = p1 -> next;
            } else {
                p2 -> next = p;
                p2 = p2 -> next;
            }
            p = p -> next;
        }
        p1 -> next = p2 -> next = NULL;
        root -> left = sortedListToBST(a -> next);
        root -> right = sortedListToBST(b -> next);
        delete a;
        delete b;
        return root;
    }
};