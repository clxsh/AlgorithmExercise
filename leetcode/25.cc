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
private:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *t = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return t;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newhead = new ListNode(0);
        ListNode *pre = newhead;        

        newhead->next = head;
        ListNode *first = head;
        ListNode *last = first;
        
        ListNode *newfirst = nullptr;
        while (last != nullptr) {
            for (int i = 0; i < k - 1; ++i) {
                if (last != nullptr)
                    last = last->next;
                else {
                    last = nullptr;
                    break;
                }                    
            }
            if (last != nullptr)
                newfirst = last->next;
            else
                break;

            last->next = nullptr;
            ListNode *t = reverseList(first);
            pre->next = t;
            first->next = newfirst;

            pre = first;
            first = newfirst;
            last = first;
        }

        return newhead->next;
    }
};