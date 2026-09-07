/*
 * 1221. Split a String in Balanced Strings
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.3 MB (beats 85.4%)
 * Submitted: 2026-03-31 13:26:34 UTC
 * URL: https://leetcode.com/submissions/detail/1964875188/
 */

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, countR = 0, countL = 0;
        for(char c : s) {
            if(c == 'R') countR++;
            else countL++;
            
            if(countR == countL) {
                res++;
                countR = 0; countL = 0;
            }
        }
        return res;
    }
};
/**
Approach: Greedy
- scan left to right, keep CountR and CountL
- if equals, record
**/
