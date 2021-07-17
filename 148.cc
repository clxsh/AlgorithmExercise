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
// private:
//     ListNode *mergeList(ListNode *l1, ListNode *l2)
//     {
//         ListNode *dummy = new ListNode(0);
//         ListNode *pre = dummy;

//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val <= l2->val) {
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

// public:
//     ListNode* sortList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr)
//             return head;

//         ListNode *fast = head->next;    // !!!
//         ListNode *slow = head;

//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode *head2 = slow->next;
//         slow->next = nullptr;
//         ListNode *l1 = sortList(head);
//         ListNode *l2 = sortList(head2);

//         return mergeList(l1, l2);
//     }
// };

class Solution {
private:
    ListNode *mergeList(ListNode *h1, ListNode *h2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;

        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val < h2->val) {
                pre->next = h1;
                h1 = h1->next;
            }
            else {
                pre->next = h2;
                h2 = h2->next;
            }
            pre = pre->next;
        }

        if (h1 != nullptr) {
            pre->next = h1;
        }

        if (h2 != nullptr) {
            pre->next = h2;
        }

        return dummy->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        int length = 0;
        ListNode *node = head;
        while (node != nullptr) {
            ++length;
            node = node->next;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        for (int sublength = 1; sublength < length; sublength *= 2) {
            ListNode *pre  = dummy;
            ListNode *next = dummy->next;
            while (next != nullptr) {
                ListNode *head1 = next;
                ListNode *tail1 = head1;
                for (int i = 1; i < sublength && tail1->next != nullptr; ++i) {
                    tail1 = tail1->next;
                }
                ListNode *head2 = tail1->next;
                ListNode *tail2 = head2;
                tail1->next = nullptr;
                if (tail2 == nullptr) {
                    pre->next = head1;
                    next = nullptr;
                    continue;
                }
                for (int i = 1; i < sublength && tail2->next != nullptr; ++i) {
                    tail2 = tail2->next;
                }
                next = tail2->next;
                tail2->next = nullptr;

                pre->next = mergeList(head1, head2);
                while (pre->next != nullptr) {
                    pre = pre->next;
                }
            }
        }

        return dummy->next;
    }
};