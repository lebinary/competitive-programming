#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        bool rev = false;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            if (rev) reverse(level.begin(), level.end());
            res.push_back(level);
            rev = !rev;
        }

        return res;
    }
};
