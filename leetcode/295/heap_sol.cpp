#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class SegTreeNode {
  public:
    int l, r, minIdx, maxIdx;
    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int l, int r) {
        this->l = l;
        this->r = r;
        this->minIdx = this->maxIdx = -1;
        this->left = this->right = nullptr;
    }
};

class MedianFinder {
  public:
    SegTreeNode *root;
    vector<int> nums;
    MedianFinder() {}

    void addNum(int num) {
        nums.push_back(num);
        if (root == nullptr) {
            root = new SegTreeNode(0, 0);
            return;
        }
    }

    double findMedian() {}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
