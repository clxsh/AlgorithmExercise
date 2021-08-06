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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        stack<TreeNode *> stk;
        TreeNode *root = new TreeNode(preorder[0]);
        stk.push(root);

        int preindex = 0;

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode *node = stk.top();
            if (inorder[preindex] != node->val) {
                node->left = new TreeNode(preorder[i]);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[preindex]) {
                    node = stk.top();
                    stk.pop();
                    ++preindex;
                }
                node->right = new TreeNode(preorder[i]);
                stk.push(node->right);
            }
        }

        return root;
    }
};