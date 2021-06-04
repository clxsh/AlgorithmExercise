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
private:
    vector<vector<int>> res;
public:
    void traverse_down(vector<int> &subpath, TreeNode *root, int target)
    {
        int subtarget = target - root->val;
        if (root->left == nullptr && root->right == nullptr && subtarget == 0) {
            subpath.push_back(root->val);
            res.push_back(subpath);
            subpath.pop_back();
            return;
        }

        subpath.push_back(root->val);
        if (root->left)
            traverse_down(subpath, root->left, subtarget);
        if (root->right)
            traverse_down(subpath, root->right, subtarget);
        subpath.pop_back();

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> t;
        if (root)
            traverse_down(t, root, target);

        return res;
    }
};