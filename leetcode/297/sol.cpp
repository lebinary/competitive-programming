#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "";

        queue<TreeNode *> q;
        q.push(root);
        string res;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();

                if (node == nullptr) {
                    res += "N|";
                } else {
                    res += to_string(node->val) + "|";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        };
        return res.substr(0, res.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "") return nullptr;

        vector<int> d;
        stringstream ss(data);
        string s;
        while (getline(ss, s, '|')) {
            d.push_back(s == "N" ? INT_MIN : stoi(s));
        }

        TreeNode *root = new TreeNode(d[0]);
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (i < d.size() && d[i] != INT_MIN) {
                TreeNode *leftNode = new TreeNode(d[i]);
                node->left = leftNode;
                q.push(leftNode);
            }
            i++;

            if (i < d.size() && d[i] != INT_MIN) {
                TreeNode *rightNode = new TreeNode(d[i]);
                node->right = rightNode;
                q.push(rightNode);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
