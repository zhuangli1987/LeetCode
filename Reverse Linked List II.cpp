/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = new ListNode(-1);
        ListNode *pre = ret, *tp = NULL, *last = NULL;
        ret -> next = head;
        head = ret;
        for (int i = 0; i <= n; ++i) {
            if (i == m - 1) {
                pre = ret;
            }
            if (i == m) {
                tp = ret;
                last = ret;
            }
            if (i > m) {
                tp -> next = ret -> next;
                pre -> next = ret;
                ret -> next = last;
                last = ret;
                ret = tp;
            }
            ret = ret -> next;
        }
        return head -> next;
    }
};