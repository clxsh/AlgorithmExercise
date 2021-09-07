/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        stack<TreeNode *> stk;
        TreeNode *pre = nullptr;
        TreeNode *cur = root;

        while (!stk.empty() || cur != nullptr) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (pre != nullptr && pre->val >= cur->val)
                return false;
            pre = cur;
            cur = cur->right;
        }

        return true;
    }
};