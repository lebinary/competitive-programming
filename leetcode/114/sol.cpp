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
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left == nullptr) return;
        if (root->right == nullptr) {
            root->right = root->left;
            root->left = nullptr;
        } else {
            TreeNode *curr = root->left;
            TreeNode *prev = nullptr;
            while (curr != nullptr) {
                prev = curr;
                curr = curr->right;
            }

            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
