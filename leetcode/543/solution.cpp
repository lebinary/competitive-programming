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
    int best;
    int diameterOfBinaryTree(TreeNode *root) {
        this->best = 0;
        dfs(root);
        return best;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int leftHeight = dfs(root->left), rightHeight = dfs(root->right);
        best = max(best, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};
