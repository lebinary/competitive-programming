/*
 * 66. Plus One
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.6 MB (beats 26.2%)
 * Submitted: 2026-03-26 19:29:38 UTC
 * URL: https://leetcode.com/submissions/detail/1960301865/
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        
        int i = 0, carry = 1;
        while(i < n && carry) {
            int val = digits[i] + carry;

            digits[i] = val % 10;
            carry = val / 10;
            i++;
        }

        if(carry) digits.push_back(1);

        reverse(digits.begin(), digits.end());
        return digits;
    }
};
