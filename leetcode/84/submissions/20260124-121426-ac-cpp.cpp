/*
 * 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 2458 ms (beats 5.3%)
 * Memory: 214.8 MB (beats 5.0%)
 * Submitted: 2026-01-24 12:14:26 UTC
 * URL: https://leetcode.com/submissions/detail/1895296667/
 */


class SegTreeNode {
  public:
    int start;
    int end;
    int minIdx;
    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = this->right = nullptr;
    }
};

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        SegTreeNode *root = buildTree(heights, 0, n - 1);
        return substructure(heights, root, n, 0, n - 1);
    }

    int substructure(vector<int> &heights, SegTreeNode *root, int n, int l, int r) {
        if (l > r) return 0;

        int minIdx = getMinIdx(heights, root, l, r);

        int curr = heights[minIdx] * (r - l + 1);
        int left = substructure(heights, root, n, l, minIdx - 1);
        int right = substructure(heights, root, n, minIdx + 1, r);

        return max({curr, left, right});
    }

    SegTreeNode *buildTree(vector<int> &heights, int start, int end) {
        if (start > end) return nullptr;
        SegTreeNode *root = new SegTreeNode(start, end);
        if (start == end) {
            root->minIdx = start;
        } else {
            int mid = start + (end - start) / 2;
            root->left = buildTree(heights, start, mid);
            root->right = buildTree(heights, mid + 1, end);
            root->minIdx = heights[root->left->minIdx] < heights[root->right->minIdx] ? root->left->minIdx : root->right->minIdx;
        }

        return root;
    }

    int getMinIdx(vector<int> &heights, SegTreeNode *root, int start, int end) {
        if (root == nullptr || start > root->end || end < root->start) return -1;
        if (start <= root->start && end >= root->end) return root->minIdx;

        int leftIdx = getMinIdx(heights, root->left, start, end);
        int rightIdx = getMinIdx(heights, root->right, start, end);
        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;
        return heights[leftIdx] < heights[rightIdx] ? leftIdx : rightIdx;
    }
};

