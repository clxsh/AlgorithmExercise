/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        return recur(root->left, root->right);
    }

    bool recur(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr || left->val != right->val) return false;

        return recur(left->right, right->left) && recur(left->left, right->right);
    }
};