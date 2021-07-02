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
//     bool hasCycle(ListNode *head) {
//         ListNode *fast = head;
//         ListNode *slow = head;
//         while (fast != nullptr) {
//             fast = fast->next;
//             if (fast != nullptr) {
//                 fast = fast->next;
//             }

//             if (fast == slow)
//                 return true;
//             slow = slow->next;
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }

        return false;
    }
};