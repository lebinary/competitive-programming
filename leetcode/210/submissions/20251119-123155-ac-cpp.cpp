/*
 * 210. Course Schedule II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 14 ms (beats 6.6%)
 * Memory: 20.3 MB (beats 5.3%)
 * Submitted: 2025-11-19 12:31:56 UTC
 * URL: https://leetcode.com/submissions/detail/1834202180/
 */


class Solution {
  public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < numCourses; ++i) adj[i] = {};
        for (vector<int> pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> seen;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(adj, seen, i)) return {};
        }

        return res;
    }

    bool dfs(unordered_map<int, vector<int>> &adj, unordered_set<int> &seen, int i) {
        if (seen.count(i)) return false;
        if (!adj.count(i)) return true;

        seen.insert(i);
        for (int prei : adj[i]) {
            if (!dfs(adj, seen, prei)) return false;
        }

        seen.erase(i);
        adj.erase(i);
        res.push_back(i);
        return true;
    }
};
