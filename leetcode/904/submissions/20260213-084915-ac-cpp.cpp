/*
 * 904. Fruit Into Baskets
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 35 ms (beats 82.2%)
 * Memory: 84.9 MB (beats 34.4%)
 * Submitted: 2026-02-13 08:49:15 UTC
 * URL: https://leetcode.com/submissions/detail/1917817247/
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), res = 0;
        unordered_map<int, int> freq;
        int l = 0;
        for(int r = 0; r < n; ++r) {
            freq[fruits[r]]++;

            while(l <= r && freq.size() > 2) {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
