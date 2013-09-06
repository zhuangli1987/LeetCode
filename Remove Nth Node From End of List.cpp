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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p1 = new ListNode(-1);
        p1 -> next = head;
        ListNode *p2 = p1, *p3 = p1, *pre;
        for (int i = 0; i < n; ++i) {
            p2 = p2 -> next;
        }
        while (p2 -> next) {
            pre = p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        p1 -> next = p1 -> next -> next;
        
        head = p3 -> next;
        delete p3;
        return head;
    }
};
