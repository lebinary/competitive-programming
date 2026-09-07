/*
 * 997. Find the Town Judge
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 50 ms (beats 7.8%)
 * Memory: 79.7 MB (beats 5.6%)
 * Submitted: 2025-05-11 10:36:07 UTC
 * URL: https://leetcode.com/submissions/detail/1630950960/
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<unordered_set<int>, int>> edges(n+1, {unordered_set<int>(), 0});

        for (const auto& pair : trust) {
            int from = pair[0], to = pair[1];
            edges[from].first.insert(to);
            edges[to].second++;
        }

        for (int i = 1; i <= n; ++i) {
            if (edges[i].first.empty() && edges[i].second == n-1) {
                return i;
            }
        }

        return -1;
    }
};
