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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *p = NULL;
        ListNode *head = l1;
        while(l1 && l2) {
            p = l1;
            l1 -> val += l2 -> val;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if (l2) {
            p -> next = l2;
        }
        p = head;
        int add = 0;
        while (p) {
            l1 = p;
            p -> val += add;
            if (p -> val > 9) {
                p -> val -= 10;
                add =1;
            } else {
                add = 0;
            }
            p = p -> next;
        }
        p = l1;
        if (add) {
            p -> next = new ListNode(1);
        }
        return head;
        
    }
};