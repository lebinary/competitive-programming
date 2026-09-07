/*
 * 2402. Meeting Rooms III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 157 ms (beats 23.9%)
 * Memory: 111.1 MB (beats 100.0%)
 * Submitted: 2025-12-28 06:20:06 UTC
 * URL: https://leetcode.com/submissions/detail/1867315146/
 */

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> res(n, 0);
        priority_queue<vector<uint>, vector<vector<uint>>, greater<vector<uint>>> used;
        priority_queue<uint, vector<uint>, greater<uint>> unused;
        for (int i = 0; i < n; ++i) unused.push(i);

        for (vector<int> &meeting : meetings) {
            uint start = meeting[0], end = meeting[1];
            uint duration = end - start;

            while (!used.empty() && used.top()[0] <= start) {
                unused.push(used.top()[1]);
                used.pop();
            }

            if (unused.empty()) {
                uint prevEnd = used.top()[0], room = used.top()[1];
                used.pop();
                used.push({prevEnd + duration, room});
                res[room]++;
            } else {
                uint room = unused.top();
                unused.pop();
                used.push({end, room});
                res[room]++;
            }
        }

        return max_element(res.begin(), res.end()) - res.begin();
    };
};
