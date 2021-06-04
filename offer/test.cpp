#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void stringsplit(string &s, vector<string> &res)
{
    int slen = s.length();

    for (int i = 1; i < slen; ++i) {
        // cout << "test: " << i  << " " << s[i] << endl;
        if (s[i] == 'n') {
            res.push_back("null");
            i += 4;
        }
        else if(s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
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

TreeNode* deserialize(string data) {
        if (data == "[]")
            return nullptr;

        vector<string> elements;
        stringsplit(data, elements);

        for (string e : elements)
            cout << e << endl;

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
        int size = elements.size();
        while (!q.empty() && eleindex < size) {
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

int main()
{
    string s = "[-1,0,1]";
    vector<string> res;

    cout << serialize(deserialize(s)) << endl;

    return 0;
}