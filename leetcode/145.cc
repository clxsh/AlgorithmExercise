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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> res;

        TreeNode *cur = root;
        TreeNode *last = nullptr;
        while (cur != nullptr || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            if (cur->right == nullptr || cur->right == last) {
                res.push_back(cur->val);
                stk.pop();
                last = cur;
                cur = nullptr;
            }
            else{
                cur = cur->right;
            }
        }

        return res;
    }
};