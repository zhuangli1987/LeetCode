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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        priority_queue< pair<int, ListNode *> > pq;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode * next = lists[i];
            if (next) {
                pq.push(make_pair(-next->val, next));
            }
        }
        while (!pq.empty()) {
            pair<int, ListNode *> t = pq.top();
            pq.pop();
            p -> next = t.second;
            p = p -> next;
            if (p -> next) {
                pq.push(make_pair(-p -> next -> val, p -> next));    
            }
        }
        p -> next = NULL;
        p = head -> next;
        delete head;
        return p;
    }
};