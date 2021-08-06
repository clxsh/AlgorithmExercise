/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *todo_pre = head;
        ListNode *todo     = head->next;

        while (todo != nullptr) {
            ListNode *pre = dummy;
            ListNode *cur = pre->next;
            ListNode *todo_next = todo->next;
            while (cur->val < todo->val && cur != todo) {
                pre = cur;
                cur = cur->next;
            }
            todo_pre->next = todo->next;
            pre->next = todo;
            todo->next = cur;

            todo = todo_next;
        }

        return dummy->next;
    }
};