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
