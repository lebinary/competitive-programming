/*
 * 340. Longest Substring with At Most K Distinct Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 11 ms (beats 18.0%)
 * Memory: 10.8 MB (beats 26.5%)
 * Submitted: 2026-02-12 09:30:50 UTC
 * URL: https://leetcode.com/submissions/detail/1916788461/
 */

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size(), res = 0;
        unordered_map<char, int> map;

        int l = 0;
        for(int r = 0; r < n; ++r) {
            map[s[r]]++;

            while(l <= r && map.size() > k) {
                map[s[l]]--;
                if(map[s[l]] == 0) map.erase(s[l]);
                l++;
            }

            if(map.size() <= k) {
                res = max(res, r - l + 1);
            }
        }

        return res;
    }
};
