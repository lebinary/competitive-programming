#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        unordered_set<string> ops = {"+", "-", "*", "/"};
        vector<string> stack;

        for (string to : tokens) {
            if (ops.find(to) != ops.end()) {
                int r = stoi(stack.back());
                stack.pop_back();

                int l = stoi(stack.back());
                stack.pop_back();

                if (to == "+") {
                    stack.push_back(to_string(l + r));
                } else if (to == "-") {
                    stack.push_back(to_string(l - r));
                } else if (to == "*") {
                    stack.push_back(to_string(l * r));
                } else {
                    stack.push_back(to_string(l / r));
                }
            } else {
                stack.push_back(to);
            }
        }

        return stoi(stack.back());
    }
};
