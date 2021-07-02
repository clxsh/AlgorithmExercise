/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// private:
//     int searchNode(TreeNode *root, TreeNode *target, deque<TreeNode *> &q)
//     {
//         if (root == target) {
//             q.push_back(root);
//             return 0;
//         }

//         TreeNode *cur = root;
//         TreeNode *last = nullptr;

//         while (cur != nullptr || !q.empty()) {
//             while (cur != nullptr) {
//                 q.push_back(cur);
//                 cur = cur->left;
//             }

//             cur = q.back();
//             if (cur->right == nullptr || last == cur->right) {
//                 if (cur == target) {
//                     break;
//                 }
//                 last = cur;
//                 q.pop_back();

//                 cur = nullptr;
//             }
//             else {
//                 cur = cur->right;
//             }
//         }

//         return 0;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         deque<TreeNode *> q1, q2;

//         searchNode(root, p, q1);
//         searchNode(root, q, q2);

//         TreeNode *res;
//         while (!q1.empty() && !q2.empty()) {
//             TreeNode *node1 = q1.front();
//             TreeNode *node2 = q2.front();
//             if (node1 != node2)
//                 break;
//             res = node1;

//             q1.pop_front();
//             q2.pop_front();
//         }

//         return res;
//     }
// };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right == nullptr)
            return nullptr;
        else if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;

        return root;
    }
};