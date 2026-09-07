/*
 * 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 16 ms (beats 58.1%)
 * Memory: 14.3 MB (beats 72.6%)
 * Submitted: 2025-08-31 06:50:27 UTC
 * URL: https://leetcode.com/submissions/detail/1754446195/
 */

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, best = 0;
        unordered_set<char> seen;

        for (int r = 0; r < n; ++r) {
            while (seen.count(s[r])) seen.erase(s[l++]);
            seen.insert(s[r]);
            best = max(best, r - l + 1);
        }

        return best;
    }
};
