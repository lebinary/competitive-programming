/*
 * 56. Merge Intervals
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 89.1%)
 * Memory: 23.8 MB (beats 82.6%)
 * Submitted: 2025-05-16 11:23:43 UTC
 * URL: https://leetcode.com/submissions/detail/1635490207/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> stack;
        for(vector<int>& interval : intervals) {
            if(stack.empty()) {
                stack.push_back(interval);
                continue;
            }

            vector<int>& last = stack.back();
            if (interval[0] > last[1]) {
                stack.push_back(interval);
            } else {
                last[1] = max(last[1], interval[1]);
            }
        }

        return stack;
    }
};
