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
int nth;
int val;
public:
    int kthLargest(TreeNode* root, int k) {
        nth = k;
        int i = 0;
        inorder(root, i);

        return val;
    }

    void inorder(TreeNode *root, int &i)
    {
        if (root->right)
            inorder(root->right, i);
            
        ++i;
        if (i == nth) {
            val = root->val;
            return;
        }
        
        if (root->left)
            inorder(root->left, i);
    }