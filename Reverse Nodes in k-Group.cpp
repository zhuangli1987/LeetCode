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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = new ListNode(-1);
        ListNode *cur, *pre, *last;
        ret -> next = head;
        head = ret;
        while (ret) {
            last = ret;
            bool checked = true;
            for (int i = 0; i <= k; ++i) {
                if (last == NULL) {
                    checked = false;
                    break;
                }
                last = last -> next;
            }
            if (!checked) {
                break;   
            }    
            for (int i = 0; i <= k && ret; ++i) {
                if (i == 0) {
                    pre = ret;
                } else if (i == 1) {
                    cur = ret;
                    last = ret;
                } else {
                    cur -> next = ret -> next;
                    pre -> next = ret;
                    ret -> next = last;
                    last = ret;
                    ret = cur;
                }
                if (i == k) {
                    break;
                }
                ret = ret -> next;
            }
        }
        return head -> next;
    }
};