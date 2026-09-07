/*
 * 43. Multiply Strings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.7 MB (beats 34.9%)
 * Submitted: 2025-07-11 12:40:33 UTC
 * URL: https://leetcode.com/submissions/detail/1694252569/
 */


class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int digit1 = num1[i] - '0', digit2 = num2[j] - '0';
                int prod = digit1 * digit2;
                int newValue = res[i + j] + prod;

                int newDigit = newValue % 10, carry = newValue / 10;

                res[i + j] = newDigit;
                res[i + j + 1] += carry;
            }
        }

        reverse(res.begin(), res.end());
        int i = 0;
        while (i < res.size() && res[i] == 0) i++;
        if (i == res.size()) return "0";
        res.erase(res.begin(), res.begin() + i);

        string resStr = "";
        for (int num : res) {
            resStr += num + '0';
        }
        return resStr;
    }
};
