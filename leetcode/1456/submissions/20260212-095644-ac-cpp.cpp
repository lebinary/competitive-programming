/*
 * 1456. Maximum Number of Vowels in a Substring of Given Length
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 15 ms (beats 10.8%)
 * Memory: 13.5 MB (beats 6.9%)
 * Submitted: 2026-02-12 09:56:45 UTC
 * URL: https://leetcode.com/submissions/detail/1916811997/
 */

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), res = 0, count = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        for(int r = 0; r < n; ++r) {
            count += vowels.count(s[r]) ? 1 : 0;
            if(r >= k) count -= vowels.count(s[r - k]) ? 1 : 0;
            res = max(res, count); 
        }

        return res;
    }
};
