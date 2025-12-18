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
    bool isValidBST(TreeNode *root) { return valid(root, LLONG_MIN, LLONG_MAX); }

    bool valid(TreeNode *node, long long maxLeft, long long minRight) {
        if (node == nullptr) return true;
        if (maxLeft >= node->val || minRight <= node->val) return false;
        return valid(node->left, maxLeft, node->val) && valid(node->right, node->val, minRight);
    }
};
