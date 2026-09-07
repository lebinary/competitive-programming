/*
 * 8. String to Integer (atoi)
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.3 MB (beats 18.9%)
 * Submitted: 2026-01-01 09:58:44 UTC
 * URL: https://leetcode.com/submissions/detail/1870891365/
 */

class Solution {
  public:
    int myAtoi(string s) {
        int state = 0, res = 0, sign = 1;

        for (char ch : s) {
            if (state == 3) break;
            if (state == 0) {
                if (ch == ' ')
                    continue;
                else if (ch == '-' || ch == '+') {
                    sign = ch == '-' ? -1 : 1;
                    state = 1;
                } else if (isdigit(ch)) {
                    int digit = ch - '0';
                    res = update(res, sign, digit);
                    if (res == INT_MIN || res == INT_MAX)
                        state = 3;
                    else
                        state = 2;
                } else {
                    state = 3;
                }
            } else {
                if (isdigit(ch)) {
                    int digit = ch - '0';
                    res = update(res, sign, digit);
                    if (res == INT_MIN || res == INT_MAX)
                        state = 3;
                    else
                        state = 2;
                } else {
                    state = 3;
                }
            }
        }

        return res * sign;
    }

    int update(int res, int &sign, int digit) {
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
            if (sign == -1) {
                sign = 1;
                return INT_MIN;
            } else
                return INT_MAX;
        } else {
            return res * 10 + digit;
        }
    }
};
