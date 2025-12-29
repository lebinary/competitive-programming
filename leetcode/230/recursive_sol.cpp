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
        return dfs(root, count, k);
    }

    int dfs(TreeNode *node, int &count, int k) {
        if (node == nullptr) return -1;

        int res = dfs(node->left, count, k);
        if (res != -1) return res;

        count++;
        if (count == k) return node->val;

        res = dfs(node->right, count, k);
        if (res != -1) return res;

        return -1;
    }
};
