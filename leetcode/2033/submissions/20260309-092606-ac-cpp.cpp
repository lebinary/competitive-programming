/*
 * 2033. Minimum Operations to Make a Uni-Value Grid
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 43 ms (beats 26.8%)
 * Memory: 97.6 MB (beats 5.3%)
 * Submitted: 2026-03-09 09:26:06 UTC
 * URL: https://leetcode.com/submissions/detail/1942696812/
 */

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int k = m * n;

        // if only 1 element, return 0
        if(k == 1) return 0;

        int remainder = grid[0][0] % x;

        vector<int> nums(k);
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {

                // check if same remainder, num A can only becomes B using ops (±x) if they share the same remainder
                if(grid[r][c] % x != remainder) return -1;
                nums[r * n + c] = grid[r][c];
            }
        }

        sort(nums.begin(), nums.end());
        vector<long long> prefixCost(k, 0);
        vector<long long> suffixCost(k, 0);

        long long cost = 0;
        for(int i = 0; i < k; ++i) {
            if(i == 0) continue;
            cost += (nums[i] - nums[i - 1]) * i;
            prefixCost[i] = cost;
        }

        cost = 0;
        for(int i = k - 1; i >= 0; --i) {
            if(i == k - 1) continue;
            cost += (nums[i+1] - nums[i]) * (k - 1 - i);
            suffixCost[i] = cost;
        }

        long long res = LLONG_MAX;
        for(int i = 0; i < k; ++i) {
            res = min(res, prefixCost[i] + suffixCost[i]);
        }

        return res / x;
    }
};

/**
Approach1: Sort + BS on the num operations + Validate
- Turn grid into 1D, sort
- BS on num operations => candidate
- Validate: for each nums[i]
    - if nums[i] == avg(nums.min, nums.max)
    - if nums[i] < avg(nums.min, nums.max) count += (avg - nums[i]) / x;
    - if nums[i] > avg(nums.min, nums.max) count += (avg - nums[i]) / -x;
=> Downside: dealing with division

Approach2: Two scans, left and right
- Scan left -> right, update prefixCost[i] = how much it cost to get to i from the left
- Scan right -> left, update suffixCost[i] = how much it cost to get to i from the right
- res = max(res, prefixCost[i] + suffixCost[i])
TC: O(n)
SC: O(n)
**/
