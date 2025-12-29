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
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        vector<TreeNode *> stack;
        stack.push_back(root);
        TreeNode *node = root;

        while (!stack.empty()) {
            while (node != nullptr) {
                stack.push_back(node);
                node = node->left;
            }

            node = stack.back();
            stack.pop_back();

            count++;
            if (count == k) return node->val;

            node = node->right;
        }

        return -1;
    }
};
