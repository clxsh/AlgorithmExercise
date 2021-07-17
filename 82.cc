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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        ListNode *cur = dummy->next;

        bool flag = false;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val)
                flag = true;
            while (cur != nullptr && cur->next != nullptr
                   && cur->val == cur->next->val) {
                cur = cur->next;
            }

            if (flag) {    // 重复元素存在
                pre->next = cur->next;
                cur = pre->next;
                flag = false;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};