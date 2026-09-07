/*
 * 218. The Skyline Problem
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 27 ms (beats 18.7%)
 * Memory: 31.9 MB (beats 15.6%)
 * Submitted: 2026-09-02 15:09:40 UTC
 * URL: https://leetcode.com/submissions/detail/2128585984/
 */

class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        int n = buildings.size();
        vector<vector<int>> points, res;

        for(const auto& b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        
        sort(points.begin(), points.end());

        priority_queue<int> active;
        unordered_map<int, int> inactive;

        active.push(0);

        for(const auto& p : points) {
            int x = p[0], y = p[1]; 
            bool isStart = y < 0;

            if(isStart) y *= -1;

            if(isStart) {
                if(y > active.top()) res.push_back({x, y});
                active.push(y);
            
            } else {
                inactive[y]++;

                while(active.size() > 1 
                    && inactive.count(active.top())
                    && inactive[active.top()] > 0) {
                    inactive[active.top()]--;
                    active.pop();
                }

                if(y > active.top()) res.push_back({x, active.top()});
            }
        }

        return res;
    }
};
