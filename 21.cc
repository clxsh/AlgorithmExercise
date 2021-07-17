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
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode *dummy  = new ListNode(0);
//         ListNode *pre = dummy;

//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val < l2->val) {
//                 pre->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 pre->next = l2;
//                 l2 = l2->next;
//             }
//             pre = pre->next;
//         }

//         if (l1 != nullptr) {
//             pre->next = l1;
//         }
//         if (l2 != nullptr) {
//             pre->next = l2;
//         }

//         return dummy->next;
//     }
// };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};