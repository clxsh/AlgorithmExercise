/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<ListNode *> stk;
//         ListNode *t = head;

//         while (t) {
//             stk.push(t);
//             t = t->next;
//         }

//         ListNode *tmphead = new ListNode(0);
//         t = tmphead;
//         while (!stk.empty()) {
//             t->next = stk.top();
//             stk.pop();
//             t = t->next;
//         }

//         t->next = nullptr;

//         return tmphead->next;
//     }
// };

class Solution {
public:
    ListNode * reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};