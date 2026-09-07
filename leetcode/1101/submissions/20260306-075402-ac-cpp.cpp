/*
 * 1101. The Earliest Moment When Everyone Become Friends
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 7 ms (beats 13.8%)
 * Memory: 19 MB (beats 10.0%)
 * Submitted: 2026-03-06 07:54:02 UTC
 * URL: https://leetcode.com/submissions/detail/1939583154/
 */

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int s = logs.size();
        unordered_map<int, vector<pair<int, int>>> graph;
        int l = -1, r = INT_MIN, hi = 0;

        for(vector<int>& log : logs) {
            graph[log[1]].push_back({log[2], log[0]});
            graph[log[2]].push_back({log[1], log[0]});
            r = max(r, log[0]);
        }
        r++;
        hi = r;

        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(graph, n, s, m)) r = m;
            else l = m + 1;
        }
        return l == -1 || r == hi ? -1 : l;
    }

    bool validator(unordered_map<int, vector<pair<int, int>>>& graph, int n, int s, int cand) {
        vector<int> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto [nei, time] : graph[curr]) {
                if(visited[nei] || time > cand) continue;

                q.push(nei);
                visited[nei] = true;
            }
        }

        for(int i = 0; i < visited.size(); ++i) {
            if(!visited[i]) {
                return false;
            }
        }

        return true;
    }
};

/**
Approach 1: BS + graph
- Create an adj list from the edges
- BS on the value
- Validator: check if can traverse the entire graph
    - Given a candidate time, any friendship that formed AFTER this time is INVALID


[[3,1,2],[1,1,5],[4,4,0],[0,3,4],[2,6,2]]

1-2-6
|
5

3-4-0

**/
