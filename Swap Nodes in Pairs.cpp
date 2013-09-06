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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        ListNode *ret = head;
        while (head) {
            if (head -> next) {
                swap(head->val, head->next->val);
                head = head -> next;
            }
            head = head -> next;
        }
        return ret;
    }
};