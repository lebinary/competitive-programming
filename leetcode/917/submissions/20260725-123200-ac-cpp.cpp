/*
 * 917. Reverse Only Letters
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.2 MB (beats 16.4%)
 * Submitted: 2026-07-25 12:32:00 UTC
 * URL: https://leetcode.com/submissions/detail/2080724910/
 */

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        string res(n, ' ');

        for(int i = 0; i < n; ++i) {
            if(!isalpha(s[i])) res[i] = s[i];
        }

        int l = 0;
        for(int r = n - 1; r >= 0; --r) {
            if(isalpha(s[r])) {
                while(res[l] != ' ') l++;
                res[l] = s[r];
            }
        }

        return res;
    }
};
