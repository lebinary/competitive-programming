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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
