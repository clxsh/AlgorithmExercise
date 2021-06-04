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
    vector<int> reversePrint(ListNode* head) {
        stack<int> vals;
        vector<int> ret;

        while (head) {
            vals.push(head->val);
            head = head->next;
        }

        while (!vals.empty()) {
            ret.push_back(vals.top());
            vals.pop();
        }

        return ret;
    }
};