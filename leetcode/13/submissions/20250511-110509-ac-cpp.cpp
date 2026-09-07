/*
 * 13. Roman to Integer
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3 ms (beats 75.1%)
 * Memory: 13.4 MB (beats 37.8%)
 * Submitted: 2025-05-11 11:05:10 UTC
 * URL: https://leetcode.com/submissions/detail/1630969512/
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
        for (int i = 0; i < s.size(); ++i) {
            if(i+1 < s.size() && map[s[i+1]] > map[s[i]]) {
                res -= map[s[i]];
            } else {
                res += map[s[i]];
            }
        }

        return res;
    }
};
