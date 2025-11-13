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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), root->val);
        int rootIdx = it - inorder.begin();

        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIdx);
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        root->left = buildTree(leftPreorder, leftInorder);

        vector<int> rightInorder(inorder.begin() + rootIdx + 1, inorder.end());
        vector<int> rightPreorder(preorder.begin() + 1 + leftPreorder.size(), preorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
