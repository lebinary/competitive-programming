#include <algorithm>
#include <cctype>
#include <climits>
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
    int goodNodes(TreeNode *root) { return dfs(root, root->val); }

    int dfs(TreeNode *node, int maxval) {
        if (node == nullptr) return 0;
        int count = node->val >= maxval ? 1 : 0;
        if (node->left) count += dfs(node->left, max(maxval, node->left->val));
        if (node->right) count += dfs(node->right, max(maxval, node->right->val));
        return count;
    }
};
