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
    bool recur(TreeNode *t1, TreeNode *t2)
    {
        if (!t2) return true;
        if (!t1 || t1->val != t2->val) return false;

        return recur(t1->left, t2->left) && recur(t1->right, t2->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;

        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};