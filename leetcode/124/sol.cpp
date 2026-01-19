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
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return 0;

        int best = INT_MIN;
        dfs(best, root);
        return best;
    }

    int dfs(int &best, TreeNode *node) {
        if (node == nullptr) return INT_MIN;

        int leftGain = max(0, dfs(best, node->left));
        int rightGain = max(0, dfs(best, node->right));

        best = max(best, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
};
