/*
 * 986. Interval List Intersections
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 2 ms (beats 49.0%)
 * Memory: 23 MB (beats 24.0%)
 * Submitted: 2026-03-24 08:52:23 UTC
 * URL: https://leetcode.com/submissions/detail/1957580017/
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size(); 
        vector<vector<int>> res;

        int l = 0;
        for(int r = 0; r < n; ++r) {
            while(l < m && firstList[l][1] < secondList[r][0]) l++;

            while(l < m && firstList[l][0] <= secondList[r][1]) {
                int overlapStart = max(firstList[l][0], secondList[r][0]);
                int overlapEnd = min(firstList[l][1], secondList[r][1]);
                res.push_back({overlapStart, overlapEnd});
                l++;
            };
            if(l > 0) l--;
        }

        return res;
    }
};

/**
# Analysis: 
- There are only 2 cases where overlap happens:
    - startA -> endB
    - startB -> endA
- The other cases are not overlap:
    - startA -> endA
    - startB -> endB
    - endA -> startB
    - endB -> startA

# Approach: Sliding window
- For each B's:
    while currA's end < currB's start:
        l++
    if there is overlap: capture it
**/
