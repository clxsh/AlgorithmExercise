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
//     ListNode* getKthFromEnd(ListNode* head, int k) {
//         stack<ListNode *> stk;
//         ListNode *t = head;

//         while (t) {
//             stk.push(t);
//             t = t->next;
//         }

//         for (int i = 0; i < k - 1; ++i) stk.pop();

//         return stk.top();
//     }
// };

class Solution {
public:
    ListNode * getKthFromEnd(ListNode *head, int k)
    {
        ListNode *pre  = head;
        ListNode *post = pre;

        for (int i = 0; i < k; ++i)
            post = post->next;
        
        while (post) {
            pre  = pre->next;
            post = post->next;
        }

        return pre;
    }
};