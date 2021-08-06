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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if (head == nullptr || head->next == nullptr)
//             return head;

//         ListNode *t1 = swapPairs(head->next->next);
//         ListNode *t2 = head->next;

//         head->next->next = head;
//         head->next = t1;

//         return t2;        
//     }
// };

class Solution {
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode *pre = newhead;
        while (pre->next != nullptr && pre->next->next != nullptr) {
            ListNode *s1 = pre->next;
            ListNode *s2 = pre->next->next;
            pre->next = s2;
            s1->next = s2->next;
            s2->next = s1;
            pre = s1;
        }

        return newhead->next;        
    }
};