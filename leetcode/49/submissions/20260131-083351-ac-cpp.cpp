/*
 * 49. Group Anagrams
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 25 ms (beats 24.2%)
 * Memory: 29.8 MB (beats 18.0%)
 * Submitted: 2026-01-31 08:33:51 UTC
 * URL: https://leetcode.com/submissions/detail/1902790208/
 */

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int n = strs.size();
        vector<int> freq;
        unordered_map<size_t, vector<string>> resMap;

        for (string s : strs) {
            freq.assign(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }
            resMap[hashVec(freq)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [k, v] : resMap) res.push_back(v);
        return res;
    }

    size_t hashVec(vector<int> vec) {
        size_t hash = 0;
        for (int x : vec) {
            hash = (hash * 31) + x;
        }
        return hash;
    }
};

