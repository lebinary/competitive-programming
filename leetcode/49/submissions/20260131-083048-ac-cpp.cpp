/*
 * 49. Group Anagrams
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 20 ms (beats 36.8%)
 * Memory: 29.6 MB (beats 18.5%)
 * Submitted: 2026-01-31 08:30:49 UTC
 * URL: https://leetcode.com/submissions/detail/1902788039/
 */


class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int n = strs.size();
        vector<int> freq;
        unordered_map<int, vector<string>> resMap;

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

