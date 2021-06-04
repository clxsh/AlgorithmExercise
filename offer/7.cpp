/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(vector<int> &preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right) {
            return nullptr;
        }

        TreeNode *node_root = new TreeNode(preorder[pre_left]);

        int root_index = index[preorder[pre_left]];
        int ltree_size = root_index - in_left;

        node_root->left  = myBuildTree(preorder, inorder, pre_left + 1, pre_left + ltree_size, in_left, root_index - 1);
        node_root->right = myBuildTree(preorder, inorder, pre_left + ltree_size + 1, pre_right, root_index + 1, in_right);

        return node_root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int nnode = inorder.size();
        for (int i = 0; i < nnode; ++i) {
            index[inorder[i]] = i;
        }

        return myBuildTree(preorder, inorder, 0, nnode - 1, 0, nnode - 1);
    }
};
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() <= 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stk;
        stk.push(root);

        int inorder_index = 0;

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode *node = stk.top();
            if (node->val != inorder[inorder_index]) {
                node->left = new TreeNode(preorder[i]);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorder_index]) {
                    node = stk.top();
                    stk.pop();                                      
                    inorder_index++;
                }
                node->right = new TreeNode(preorder[i]);
                stk.push(node->right);
            }
        }

        return root;
    }
};