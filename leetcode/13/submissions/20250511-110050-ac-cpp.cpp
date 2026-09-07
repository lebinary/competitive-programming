/*
 * 13. Roman to Integer
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 6 ms (beats 56.0%)
 * Memory: 13.2 MB (beats 57.4%)
 * Submitted: 2025-05-11 11:00:51 UTC
 * URL: https://leetcode.com/submissions/detail/1630966710/
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} 
        };

        int res = 0;
        int i = 0;
        while (i < s.size()) {
            if(!s[i+1]) {
                res += map[s[i++]];
                continue;
            }

            int a = map[s[i]], b = map[s[i+1]];
            if(a < b) {
                res += b - a;
                i += 2; 
            }else {
                res += a;
                i++;
            }
        }

        return res;
    }
};
