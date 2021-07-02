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
//     int searchNode(TreeNode *root, TreeNode *target, queue<TreeNode *> &q)
//     {
//         q.push(root);
//         while (root && root != target) {
//             if (target->val < root->val) {
//                 root = root->left;
//             }
//             else {
//                 root = root->right;
//             }
//             q.push(root);
//         }

//         return 0;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         queue<TreeNode *> q1, q2;

//         searchNode(root, p, q1);
//         searchNode(root, q, q2);

//         TreeNode *res = NULL;
//         while (!q1.empty() && !q2.empty()) {
//             TreeNode *node1 = q1.front();
//             TreeNode *node2 = q2.front();
//             cout << node1->val << endl;
//             if (node1 != node2) {
//                 break;
//             }
//             res = node1;

//             q1.pop();
//             q2.pop();
//         }

//         return res;
//     }
// };

class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
     {
         TreeNode *ancestor = root;
         while (true) {
             if (ancestor->val < p->val && ancestor->val < q->val) {
                 ancestor = ancestor->right;
             }
             else if (ancestor->val > p->val && ancestor->val > q->val) {
                 ancestor = ancestor->left;
             }
             else {
                 break;
             }
         }

         return ancestor;
     }
};