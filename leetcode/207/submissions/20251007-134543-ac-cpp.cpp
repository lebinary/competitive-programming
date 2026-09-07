/*
 * 207. Course Schedule
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 17 ms (beats 7.7%)
 * Memory: 22 MB (beats 5.2%)
 * Submitted: 2025-10-07 13:45:44 UTC
 * URL: https://leetcode.com/submissions/detail/1794232421/
 */


class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> prereqs;
        for (int i = 0; i < numCourses; ++i) prereqs[i] = {};
        for (vector<int> pre : prerequisites) prereqs[pre[0]].push_back(pre[1]);

        unordered_set<int> seen;
        vector<int> dp = vector<int>(numCourses, -1);
        for (auto &pair : prereqs) {
            if (has_loop(prereqs, seen, pair.first)) return false;
        }

        return true;
    }

    bool has_loop(unordered_map<int, vector<int>> &prereqs, unordered_set<int> &seen, int course) {
        if (prereqs[course].size() == 0) return false;
        if (seen.find(course) != seen.end()) return true;

        seen.insert(course);
        for (int nextCourse : prereqs[course]) {
            if (has_loop(prereqs, seen, nextCourse)) return true;
        }
        seen.erase(course);

        prereqs[course] = {};
        return false;
    }
};
