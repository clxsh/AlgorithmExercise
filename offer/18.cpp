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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) return head->next;

        ListNode *pre = head;
        ListNode *next = pre->next;

        while (next) {
            if (next->val == val) {
                pre->next = next->next;
                break;
            }
            pre = next;
            next = pre->next;
        }

        return head;
    }
};