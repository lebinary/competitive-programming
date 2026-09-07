/*
 * 395. Longest Substring with At Least K Repeating Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 15 ms (beats 48.3%)
 * Memory: 8.6 MB (beats 93.1%)
 * Submitted: 2026-07-24 09:48:53 UTC
 * URL: https://leetcode.com/submissions/detail/2079409466/
 */

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;

        for(int uniq = 1; uniq <= 26; uniq++) {
            vector<int> freq(26, 0);

            int l = 0;
            for(int r = 0; r < s.size(); ++r) {
                freq[s[r] - 'a'] += 1;

                while(l <= r && !valid(freq, uniq)) {
                    freq[s[l] - 'a'] -= 1;
                    l++;
                }

                bool hasLessThanK = any_of(freq.begin(), freq.end(), [k](int x) {
                    return x > 0 && x < k;
                });

                if(!hasLessThanK) {
                    res = max(res, r - l + 1);
                }
            }
        }

        return res;
    }

    bool valid(vector<int>& freq, int uniq) {
        int count = 0;
        for(int i = 0; i < 26; ++i) {
            if(freq[i] > 0) count++;
            if(count > uniq) return false;
        }
        return true;
    }
};
