/*
 * 207. Course Schedule
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 11 ms (beats 21.4%)
 * Memory: 21 MB (beats 7.0%)
 * Submitted: 2026-01-01 10:41:28 UTC
 * URL: https://leetcode.com/submissions/detail/1870917447/
 */

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (int course = 0; course < numCourses; course++) graph[course] = {};
        for (vector<int> &pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> seen;
        vector<int> dp(numCourses, -1);
        for (vector<int> &pre : prerequisites) {
            if (dfs(graph, seen, dp, pre[0])) return false;
        }

        return true;
    };

    bool dfs(unordered_map<int, vector<int>> &graph, unordered_set<int> &seen, vector<int> &dp, int curr) {
        if (graph[curr].size() == 0) return false;
        if (seen.count(curr)) return true;
        if (dp[curr] != -1) return dp[curr];

        seen.insert(curr);
        for (int pre : graph[curr]) {
            if (dfs(graph, seen, dp, pre)) return dp[curr] = true;
        }
        seen.erase(curr);

        return dp[curr] = false;
    }
};
