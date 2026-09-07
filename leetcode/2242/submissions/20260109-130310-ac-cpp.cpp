/*
 * 2242. Maximum Score of a Node Sequence
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 2234 ms (beats 5.1%)
 * Memory: 519.8 MB (beats 5.5%)
 * Submitted: 2026-01-09 13:03:10 UTC
 * URL: https://leetcode.com/submissions/detail/1879765376/
 */


class Solution {
  public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
        unordered_map<int, vector<pair<int, int>>> ds;

        for (vector<int> &e : edges) {
            int u = e[0], v = e[1];

            ds[u].push_back({scores[v], v});
            push_heap(ds[u].begin(), ds[u].end(), greater<>());
            if (ds[u].size() > 3) {
                pop_heap(ds[u].begin(), ds[u].end(), greater<>());
                ds[u].pop_back();
            }

            ds[v].push_back({scores[u], u});
            push_heap(ds[v].begin(), ds[v].end(), greater<>());
            if (ds[v].size() > 3) {
                pop_heap(ds[v].begin(), ds[v].end(), greater<>());
                ds[v].pop_back();
            }
        }

        int best = -1;

        for (vector<int> &e : edges) {
            int u = e[0], v = e[1];
            for (auto [_, unei] : ds[u]) {
                for (auto [_, vnei] : ds[v]) {
                    if (valid(u, v, unei, vnei)) {
                        best = max(best, scores[u] + scores[v] + scores[unei] + scores[vnei]);
                    }
                }
            }
        }

        return best;
    }

    bool valid(int u, int v, int unei, int vnei) {
        unordered_set<int> s = {u, v, unei, vnei};
        return s.size() == 4;
    }
};
