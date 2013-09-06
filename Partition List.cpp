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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return head;
        }
        ListNode *p1 = head;
        ListNode *small = NULL;
        ListNode *big = NULL;
        ListNode *sh = NULL;
        ListNode *bh = NULL;
        while (p1) {
            ListNode *next = p1 -> next;
            if (p1 -> val < x) {
                if (!small) {
                    small = p1;
                    sh = small;
                    small -> next = NULL;
                } else {
                    small -> next = p1;
                    small = small -> next;
                    small -> next = NULL;
                }
            } else {
                if (!big) {
                    big = p1; 
                    bh = big;
                    big -> next = NULL;
                } else {
                    big -> next = p1;
                    big = big -> next;
                    big -> next = NULL;
                }
            }
            p1 = next;
        }
        if (sh) {
            small -> next = bh;
        } else {
            sh = bh;
        }
        return sh;
    }
};