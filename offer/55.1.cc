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
    int gdepth;
    void dfs(TreeNode *root, int depth)
    {
        if (root == nullptr) {
            gdepth = max(depth, gdepth);
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);        
    }

public:
    int maxDepth(TreeNode* root)
    {
        dfs(root, 0);
        
        return gdepth;
    }
};