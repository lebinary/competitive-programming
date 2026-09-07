/*
 * 150. Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17.5 MB (beats 7.8%)
 * Submitted: 2025-08-31 05:03:04 UTC
 * URL: https://leetcode.com/submissions/detail/1754343036/
 */


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
