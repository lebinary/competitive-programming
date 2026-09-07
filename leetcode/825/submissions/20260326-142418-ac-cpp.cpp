/*
 * 825. Friends Of Appropriate Ages
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 44 ms (beats 6.9%)
 * Memory: 41 MB (beats 84.9%)
 * Submitted: 2026-03-26 14:24:18 UTC
 * URL: https://leetcode.com/submissions/detail/1959983693/
 */

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size(), res = 0;

        for(int y = 0; y < n; ++y) {
            int l = 0, r = y;
            while(l < r) {
                int m = l + (r - l) / 2;
                if(valid(ages, y, m)) r = m;
                else l = m + 1;
            }
            int xLeft = l;

            l = y, r = n - 1;
            while(l < r) {
                int m = l + (r - l + 1) / 2;
                if(valid(ages, y, m)) l = m;
                else r = m - 1;
            } 
            int xRight = l;

            if(valid(ages, y, xLeft) && valid(ages, y, xRight)) res += xRight - xLeft;
        }

        return res;
    }

    bool valid(vector<int>& ages, int y, int x) {
        return ages[x] * 0.5 + 7 < ages[y] && ages[y] <= ages[x];
    }
};

/**
# Analysis: x will send request to y if 
- y <= 100 || x >= 100
- x >= y > x/2 + 7
=> second condition overwrite the first

# Approach 1: Sort + Sliding Window
- Sort age non-decreasing
- For each age[r]
    l is the first to be correct
    res += r - l
=> counting valid pairs, but not account for "direction"

# Approach 2: Sort + Binary search
- Sort non-dec
- For each y:
    find leftmost valid x
    find rightmost valid x
    res += rightmost - leftmost
- return res
**/
