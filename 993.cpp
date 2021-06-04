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
// class Solution {
// private:
//     int x;
//     bool x_found = false;
//     int x_depth;
//     TreeNode *x_parent;

//     int y;
//     bool y_found = false;
//     int y_depth;
//     TreeNode *y_parent;



// public:
//     void dfs(TreeNode *root, int depth, TreeNode *parent)
//     {
//         if (!root) return;

//         if (root->val == x) {
//             // x_found = true;
//             // x_depth = depth;
//             // x_parent = parent;
//             tie(x_found, x_depth, x_parent) = tuple(true, depth, parent);
//         }
//         else if (root->val == y) {
//             // y_found = true;
//             // y_depth = depth;
//             // y_parent = parent;
//             tie(y_found, y_depth, y_parent) = tuple(true, depth, parent);
//         }

//         if (x_found && y_found) {
//             return;
//         }
//         dfs(root->left, depth + 1, root);

//         if (x_found && y_found) {
//             return;
//         }
//         dfs(root->right, depth + 1, root);
        
//     }

//     bool isCousins(TreeNode* root, int x, int y) {
//         this->x = x;
//         this->y = y;
//         dfs(root, 0, nullptr);

//         return x_depth == y_depth && x_parent != y_parent;
//     }
// };

class Solution {
private:
    int x;
    bool x_found;
    int x_depth;
    TreeNode *x_parent;

    int y;
    bool y_found;
    int y_depth;
    TreeNode *y_parent;

public:
    void update(TreeNode *node, TreeNode *parent, int depth)
    {
        if (node->val == x) {
            tie(x_found, x_depth, x_parent) = tuple(true, depth, parent);
        }
        else if (node->val == y){
            tie(y_found, y_depth, y_parent) = tuple(true, depth, parent);
        }
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        this->x = x;
        this->y = y;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        update(root, nullptr, 0);

        while (!q.empty()) {
            auto &&[node, depth] = q.front();
            if (node->left) {
                q.emplace(node->left, depth + 1);
                update(node->left, node, depth + 1);
            }
            if (node->right) {
                q.emplace(node->right, depth + 1);
                update(node->right, node, depth + 1);
            }
            if (x_found && y_found) {
                break;
            }
            q.pop();
        }

        return x_depth == y_depth && x_parent != y_parent;
    }
};