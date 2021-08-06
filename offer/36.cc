/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
// class Solution {
// private:
//     Node *pre, *head;
// public:
//     Node* treeToDoublyList(Node* root) {
//         if (root == nullptr)
//             return nullptr;

//         dfs(root);
//         head->left = pre;
//         pre->right = head;

//         return head;
//     }
    
//     void dfs(Node *root)
//     {
//         if (root == nullptr)
//             return;
//         dfs(root->left);
//         if (pre)
//             pre->right = root;
//         else
//             head = root;
//         root->left = pre;
//         pre = root;
//         dfs(root->right);
//     }


// };

class Solution {
public:
    Node* treeToDoublyList(Node* root)
    {
        if (root == nullptr)
            return nullptr;
            
        Node *head = nullptr;
        Node *pre = nullptr;

        stack<Node *> stk;
        Node *cur = root;

        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();

            if (pre == nullptr) {
                head = cur;
            }
            else {
                pre->right = cur;
            }
            cur->left = pre;            
            pre = cur;

            cur = cur->right;
        }
        head->left = pre;
        pre->right = head;

        return head;
    }
};