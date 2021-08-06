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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        ListNode *pre1 = odd;
        ListNode *pre2 = even;
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            pre1->next = cur;
            pre2->next = cur->next;
            pre1 = pre1->next;
            pre2 = pre2->next;
            cur = cur->next->next;
        }
        if (cur != nullptr) {
            pre1->next = cur;
            pre1 = pre1->next;
        }
        pre1->next = even->next;
        pre2->next = nullptr;

        return odd->next;
    }
};