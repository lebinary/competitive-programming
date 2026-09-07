/*
 * 218. The Skyline Problem
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 31 ms (beats 14.1%)
 * Memory: 33 MB (beats 10.5%)
 * Submitted: 2026-09-03 12:32:54 UTC
 * URL: https://leetcode.com/submissions/detail/2129598034/
 */

class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        int n = buildings.size();
        vector<vector<int>> events, res;

        for(int i = 0; i < n; ++i) {
            events.push_back({buildings[i][0], i});
            events.push_back({buildings[i][1], i});
        }
        
        sort(events.begin(), events.end());

        priority_queue<vector<int>> tallestSoFar; // store {height, building_idx}
        vector<bool> active(n);
        tallestSoFar.push({0, -1});

        int m = events.size(), j = 0;
        while(j < m) {
            int x = events[j][0];

            // set active/inactive state of building
            while(j < m && events[j][0] == x) {
                int i = events[j][1];
                int height = buildings[i][2];
                
                if(active[i]) active[i] = false;
                else {
                    active[i] = true;
                    tallestSoFar.push({height, i});
                }
                
                j++;
            }

            // add to res, if the height changes
            while(tallestSoFar.size() > 1 && active[tallestSoFar.top()[1]] == false) {
                tallestSoFar.pop();
            }

            if(res.empty() || tallestSoFar.top()[0] != res.back()[1]) {
                res.push_back({x, tallestSoFar.top()[0]});
            }
        }

        return res;
    }
};
