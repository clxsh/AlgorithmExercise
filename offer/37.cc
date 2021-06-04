/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "[]";
        string res = "[";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node) {
                res.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
            else
                res.append("null,");
        }
        res.erase(res.length() - 1);
        res.append("]");

        return res;
    }

    void stringsplit(string &s, vector<string> &res)
    {
        int slen = s.length();

        for (int i = 1; i < slen; ++i) {
            if (s[i] == 'n') {
                res.push_back("null");
                i += 4;
            }
            else if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
                int start  = i;
                int len = 0;
                while (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
                    ++len;
                    ++i;
                }
                
                res.push_back(s.substr(start, len));
            }
            else {
                break;
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return nullptr;

        vector<string> elements;
        stringsplit(data, elements);

        TreeNode *head;
        if (elements[0][0] != 'n') {
            head = new TreeNode(stoi(elements[0]));
        }
        else {
            return nullptr;
        }
        
        queue<TreeNode *> q;
        q.push(head);
        int eleindex = 1;

        while (!q.empty() && eleindex < elements.size()) {
            TreeNode *node = q.front();
            q.pop();
            if (elements[eleindex][0] != 'n') {
                node->left = new TreeNode(stoi(elements[eleindex]));
                q.push(node->left);
            }
            eleindex++;
            
            if (elements[eleindex][0] != 'n') {
                node->right = new TreeNode(stoi(elements[eleindex]));
                q.push(node->right);
            }
            eleindex++;
        }

        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));