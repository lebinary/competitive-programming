/*
 * 763. Partition Labels
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.8 MB (beats 86.1%)
 * Submitted: 2025-08-31 06:29:36 UTC
 * URL: https://leetcode.com/submissions/detail/1754424698/
 */


class Solution {
  public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> last;
        vector<int> res;

        for (int i = 0; i < n; ++i) {
            last[s[i]] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i]]);

            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
