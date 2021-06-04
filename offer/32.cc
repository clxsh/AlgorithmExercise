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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> res;
        vector<int> sv;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                sv.push_back(node->val);
            }
            res.push_back(sv);
            sv.clear();
        }

        return res;
    }
};