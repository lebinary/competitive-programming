#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> prereqs;
        for (int i = 0; i < numCourses; ++i) prereqs[i] = {};
        for (vector<int> pre : prerequisites) prereqs[pre[0]].push_back(pre[1]);

        unordered_set<int> seen;
        vector<int> dp = vector<int>(numCourses, -1);
        for (auto &pair : prereqs) {
            if (has_loop(prereqs, seen, dp, pair.first)) return false;
        }

        return true;
    }

    bool has_loop(unordered_map<int, vector<int>> &prereqs, unordered_set<int> &seen, vector<int> &dp, int course) {
        if (prereqs.find(course) == prereqs.end()) return false;
        if (seen.find(course) != seen.end()) return true;
        if (dp[course] != -1) return dp[course];

        seen.insert(course);
        for (int nextCourse : prereqs[course]) {
            if (has_loop(prereqs, seen, dp, nextCourse)) return dp[course] = true;
        }
        seen.erase(course);

        return dp[course] = false;
    }
};
