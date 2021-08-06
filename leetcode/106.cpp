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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }

        stack<TreeNode *> stk;
        int pindex = postorder.size() - 1;
        int iindex = pindex;
        TreeNode *root = new TreeNode(postorder[pindex]);
        stk.push(root);

        for (pindex = pindex - 1; pindex >= 0; --pindex) {
            TreeNode *node = stk.top();
            if (inorder[iindex] != node->val) {
                node->right = new TreeNode(postorder[pindex]);
                stk.push(node->right);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[iindex]) {
                    node = stk.top();
                    stk.pop();
                    --iindex;
                }
                node->left = new TreeNode(postorder[pindex]);
                stk.push(node->left);
            }
        }

        return root;

    }
};