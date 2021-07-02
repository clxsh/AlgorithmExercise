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
private:
    int recur(TreeNode *root)
    {
        if (root == NULL) return 0;

        int left = recur(root->left);
        if (left == -1)
            return -1;

        int right = recur(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) <= 1)
            return max(left, right) + 1;
        else
            return -1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return recur(root) == -1 ? false : true;
    }
};