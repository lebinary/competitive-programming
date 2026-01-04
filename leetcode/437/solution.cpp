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
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfs(TreeNode *node, long long remain) {
        if (node == nullptr) return 0;

        int count = node->val == remain ? 1 : 0;
        count += dfs(node->left, remain - node->val);
        count += dfs(node->right, remain - node->val);

        return count;
    }
};
