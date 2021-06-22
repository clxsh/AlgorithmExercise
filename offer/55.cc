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
int maxdep;
private:
    void work(TreeNode *root, int depth)
    {
        ++depth;
        if (root->left) {
            work(root->left, depth);
        }
        else {
            maxdep = max(depth, maxdep);
        }

        if (root->right) {
            work(root->right, depth);
        }
        else {
            maxdep = max(depth, maxdep);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
            
        work(root, 0);

        return maxdep;
    }
};