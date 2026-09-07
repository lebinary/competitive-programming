/*
 * 224. Basic Calculator
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 30 ms (beats 5.2%)
 * Memory: 27.3 MB (beats 5.0%)
 * Submitted: 2026-03-31 12:17:04 UTC
 * URL: https://leetcode.com/submissions/detail/1964819516/
 */

class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int sign = 1;
        string operand = "";
        stack<pair<int, string>> st;

        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') continue;
            else if(s[i] == '(') {
                st.push({sign, "("});
                sign = 1;
            } else if(isdigit(s[i])) {
                operand += s[i];
            } else if(s[i] == '+') {
                if(operand.size() > 0) {
                    st.push({sign, operand});
                    operand = "";
                }
                sign = 1;
            } else if(s[i] == '-') {
                if(operand.size() > 0) {
                    st.push({sign, operand});
                    operand = "";
                }
                sign = -1;
            } else {
                if(operand.size() > 0) {
                    st.push({sign, operand});
                    operand = "";
                }

                int res = 0;
                while(!st.empty() && st.top().second != "(") {
                    res += st.top().first * stoi(st.top().second);
                    st.pop();
                }

                int innerSign = 1;
                if(!st.empty()) {
                    innerSign = st.top().first;
                    st.pop();
                }

                res *= innerSign;
                st.push({1, to_string(res)});

                sign = 1;
            }
        }


        // last operand
        if(operand.size() > 0) {
            st.push({sign, operand});
            operand = "";
        }
        
        // process the outer-most expression
        long long res = 0;
        while(!st.empty()) {
            res += st.top().first * stoll(st.top().second);
            st.pop();
        }

        return res;
    }
};

/**
# Approach 2: Stack, store (sign, operand) on the stack
- Only store result of expression on the stack, calculate expression on the go
- Example: "3 - (23 - 10)"
    stack = [{+, 3}, {-, (}, {+, 23}, {-, 10}]

- How to deal with operand >= 10?
    - when '+', '-', ')'
        - push {sign, operand}
        - pop until see '(' on top of the stack
        - update the sign
    - when 'digit':
        - build the operand
    - when '(':
        - push {sign, '('}

TC: O(n)
SC: O(n)
**/
