/*
 * 242. Valid Anagram
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.9 MB (beats 11.4%)
 * Submitted: 2025-05-03 12:32:29 UTC
 * URL: https://leetcode.com/submissions/detail/1624384653/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }

        return countS == countT;
    }
};
