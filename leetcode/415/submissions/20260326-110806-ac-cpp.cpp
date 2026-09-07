/*
 * 415. Add Strings
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.1 MB (beats 56.0%)
 * Submitted: 2026-03-26 11:08:07 UTC
 * URL: https://leetcode.com/submissions/detail/1959830171/
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res = ""; 
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i = 0;
        int val = 0, carry = 0;
        while(i < m && i < n) {
            val = carry;
            val += (num1[i] - '0');
            val += (num2[i] - '0');

            res += (val % 10) + '0';
            carry = val / 10;
            i++;
        }

        while(i < m) {
            val = carry;
            val += (num1[i] - '0');

            res += (val % 10) + '0';
            carry = val / 10;
            i++;
        }

        while(i < n) {
            val = carry;
            val += (num2[i] - '0');

            res += (val % 10) + '0';
            carry = val / 10;
            i++;
        }

        if(carry) res += (carry + '0');

        reverse(res.begin(), res.end());
        return res;
    }
};
