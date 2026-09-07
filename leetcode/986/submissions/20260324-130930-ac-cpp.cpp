/*
 * 986. Interval List Intersections
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22.9 MB (beats 85.4%)
 * Submitted: 2026-03-24 13:09:31 UTC
 * URL: https://leetcode.com/submissions/detail/1957768981/
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size(); 
        vector<vector<int>> res;

        int i = 0, j = 0;
        while(i < m && j < n) {
            if(firstList[i][1] <= secondList[j][1]) {
                if(firstList[i][1] >= secondList[j][0]) {
                    int ovlStart = max(firstList[i][0], secondList[j][0]);
                    int ovlEnd = firstList[i][1];
                    res.push_back({ovlStart, ovlEnd});
                }
                i++;
            } else {
                if(firstList[i][0] <= secondList[j][1]) {
                    int ovlStart = max(firstList[i][0], secondList[j][0]);
                    int ovlEnd = secondList[j][1];
                    res.push_back({ovlStart, ovlEnd});
                }
                j++;
            }
        }

        return res;
    }
};

/**
# Approach 2: 2 pointers
- Keeping 2 pointers, one for firstList, one for secondList
- Assume pointerA is the one with SMALLER END
    - check if pointerB overlap
- Do the same with pointerB
**/
