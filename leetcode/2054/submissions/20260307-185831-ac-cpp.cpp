/*
 * 2054. Two Best Non-Overlapping Events
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 111 ms (beats 53.5%)
 * Memory: 193.1 MB (beats 72.2%)
 * Submitted: 2026-03-07 18:58:32 UTC
 * URL: https://leetcode.com/submissions/detail/1941113508/
 */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(), res = INT_MIN;
        vector<int> postfixMax(n, 0);

        sort(events.begin(), events.end());
        for(int i = n - 1; i >= 0; --i) {
            if(i == n - 1) postfixMax[i] = events[i][2];
            else postfixMax[i] = max(postfixMax[i + 1], events[i][2]);
        }

        for(int i = 0; i < n; ++i) {
            int l = i, r = n - 1;
            while(l < r) {
                int m = l + (r - l) / 2;
                if(events[i][1] < events[m][0]) r = m;
                else l = m + 1;
            }

            res = max(res, events[i][2]);
            if(events[i][1] < events[l][0]) res = max(res, events[i][2] + postfixMax[l]);
        }

        return res;
    }
};

/**
Approach: sort by start + postfixMax + binary search
- Sort by start time
- Compute postfixMax
- For each event x:
    index = binary_search for event y s.t. x'end < y'start
    res = max(res, x's value + postfixMax[index])

    res = max(res, x's value) # "at most 2 non-overlapping"
**/
