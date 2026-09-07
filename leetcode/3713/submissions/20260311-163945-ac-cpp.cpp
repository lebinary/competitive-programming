/*
 * 3713. Longest Balanced Substring I
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 190 ms (beats 52.6%)
 * Memory: 27.2 MB (beats 29.1%)
 * Submitted: 2026-03-11 16:39:46 UTC
 * URL: https://leetcode.com/submissions/detail/1945214440/
 */

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), res = 0;
        unordered_map<char, int> freqMap;
        
        for(int i = 0; i < n; ++i) {
            freqMap.clear();

            for(int j = i; j < n; ++j) {
                freqMap[s[j]]++;

                bool valid = true;
                int freq = -1;
                for(auto [_, currFreq] : freqMap) {
                    if(freq == -1) freq = currFreq;
                    else if(freq != currFreq) {
                        valid = false;
                        break;
                    };
                }
                if(valid) res = max(res, j - i + 1);
            }
        }

        return res;
    }
};

/**
Ideas: small constraint on s: n <= 1000
- bruteforce and get the result

Approach:
- For each substr:
    - build a different freqMap
    - check if freqMap is valid
**/
