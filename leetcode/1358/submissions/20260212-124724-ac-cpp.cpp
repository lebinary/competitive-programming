/*
 * 1358. Number of Substrings Containing All Three Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 47 ms (beats 5.4%)
 * Memory: 16.8 MB (beats 13.0%)
 * Submitted: 2026-02-12 12:47:24 UTC
 * URL: https://leetcode.com/submissions/detail/1916940433/
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0;  
        unordered_map<char, int> freq;
        int l = 0;

        for(int r = 0; r < n; ++r) {
            freq[s[r]]++;
            while(l <= r && freq.size() >= 3) {
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }

            res += l;
        }

        return res;
    }
};
