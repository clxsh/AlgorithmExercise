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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;

        int carry = 0;
        while (p1 != nullptr && p2 != nullptr) {
            int num = p1->val + p2->val + carry;
            carry = num / 10;
            num = num % 10;
            pre->next = new ListNode(num);
            pre = pre->next;

            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *p3 = nullptr;
        if (p1 != nullptr) {
            p3 = p1;
        }
        if (p2 != nullptr) {
            p3 = p2;
        }

        while (carry != 0 || p3 != nullptr) {
            if (p3 != nullptr) {
                int num = p3->val + carry;
                carry = num / 10;
                num   = num % 10;
                pre->next = new ListNode(num);
                p3 = p3->next;
            }
            else {
                pre->next = new ListNode(carry);
                carry = 0;
            }
            pre = pre->next;
        }

        return dummy->next;
    }
};