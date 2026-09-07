/*
 * 3713. Longest Balanced Substring I
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 195 ms (beats 51.9%)
 * Memory: 26.9 MB (beats 30.3%)
 * Submitted: 2026-03-11 16:38:35 UTC
 * URL: https://leetcode.com/submissions/detail/1945213090/
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
**/
