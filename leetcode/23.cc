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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        for (vector<ListNode *>::iterator it = lists.begin(); it < lists.end(); ) {  // 去除空节点后判空
            if (*it == nullptr) {
                lists.erase(it);
            }
            else {
                ++it;
            }                
        }
        int lsize = lists.size();

        if (lsize == 0)
            return nullptr;


        ListNode dummy(0);
        ListNode *pre = &dummy;

        while (lsize != 0) {
            ListNode *t = lists[0];
            int tag = 0;
            for (int i = 1; i < lsize; ++i) {
                if (t->val > lists[i]->val) {
                    t = lists[i];
                    tag = i;
                }
            }
            lists[tag] = t->next;
            pre->next = t;
            pre = t;

            if (lists[tag] == nullptr)
                lists.erase(lists.begin() + tag);
            lsize = lists.size();
        }
        pre->next = nullptr;
        
        return dummy.next;
    }
};