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
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0, head);
        ListNode *lastSorted = head;
        ListNode *cur = lastSorted->next;

        while (cur != nullptr) {
            if (lastSorted->val <= cur->val) {
                // lastSorted = lastSorted->next;
                lastSorted = cur;
            }
            else {
                ListNode *t = &dummy;
                while (t->next->val <= cur->val) {
                    t = t->next;
                }
                lastSorted->next = cur->next;
                cur->next = t->next;
                t->next = cur;
            }
            cur = lastSorted->next;
        }

        return dummy.next;
    }
};