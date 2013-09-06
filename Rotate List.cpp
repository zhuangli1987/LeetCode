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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head, *tail = head, *pre = head;
        int n = 0;
        while (p) {
            p = p -> next;
            ++n;
        }
        if (n == 0) {
            return head;
        }
        k = k % n;
        k = (n - k + n) % n;
        if (k == 0) {
            return head;
        }
        p = head;
        
        for (int i = 0; i < k; ++i) {
            pre = p;
            p = p -> next;
        }
        while (tail -> next) {
            tail = tail -> next;
        }
        tail -> next = head;
        pre -> next = NULL;
        return p;
    }
};