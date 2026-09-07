/*
 * 295. Find Median from Data Stream
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 90 ms (beats 29.6%)
 * Memory: 148.4 MB (beats 92.7%)
 * Submitted: 2026-01-30 10:41:30 UTC
 * URL: https://leetcode.com/submissions/detail/1901897180/
 */

class MedianFinder {
  public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {}

    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        int n = left.size() + right.size();
        if (n % 2 == 1) {
            return left.top();
        } else {
            return 0.5 * ((double)left.top() + right.top());
        }
    }
};
