/*
 * 1762. Buildings With an Ocean View
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 42.3%)
 * Memory: 73 MB (beats 59.2%)
 * Submitted: 2026-03-17 07:47:57 UTC
 * URL: https://leetcode.com/submissions/detail/1950871141/
 */

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> res;

        for(int i = 0; i < n; ++i) {
            if(res.empty()) {
                res.push_back(i);
                continue;
            }

            while(!res.empty() && heights[i] >= heights[res.back()]) res.pop_back();
            res.push_back(i);
        }

        return res;
    }
};

/**
Monotonic stack problem
**/
