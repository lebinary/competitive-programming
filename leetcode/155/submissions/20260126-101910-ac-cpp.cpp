/*
 * 155. Min Stack
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 6 ms (beats 100.0%)
 * Memory: 23.3 MB (beats 100.0%)
 * Submitted: 2026-01-26 10:19:10 UTC
 * URL: https://leetcode.com/submissions/detail/1897457796/
 */

class MinStack {
public:
    stack<pair<int, int>> minStack;
    MinStack() {
      this->minStack = {};
    }

    void push(int val) {
      if(minStack.empty()) {
        minStack.push({val, val});
        return;
      }
      auto [_, prevMin] = minStack.top();
      minStack.push({val, min(prevMin, val)});
    }

    void pop() {
      if(minStack.empty()) return;
      minStack.pop();
    }

    int top() {
      if(minStack.empty()) return INT_MAX;
      auto [val, _] = minStack.top();
      return val;
    }

    int getMin() {
      if(minStack.empty()) return INT_MAX;
      auto [_, min] = minStack.top();
      return min;
    }
};
