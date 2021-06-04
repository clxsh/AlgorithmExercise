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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *tmphead = new ListNode(0);
        ListNode *t = tmphead;
        ListNode *t1 = l1;
        ListNode *t2 = l2;

        while (t1 && t2) {
            if (t1->val <= t2->val) {
                t->next = t1;
                t1 = t1->next;
                t = t->next;
            }
            else {
                t->next = t2;
                t2 = t2->next;
                t = t->next;
            }
        }
        if (t1)
            t->next = t1;
        if (t2)
            t->next = t2;

        return tmphead->next;

    }
};