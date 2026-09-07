/*
 * 3566. Partition Array into Two Equal Product Subsets
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1 ms (beats 64.5%)
 * Memory: 23.8 MB (beats 51.0%)
 * Submitted: 2025-06-05 15:29:16 UTC
 * URL: https://leetcode.com/submissions/detail/1654850061/
 */

typedef __int128 ll;

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();

        ll sub = 1;
        for(int num : nums) {
            sub *= num;
            if(sub > (ll)target * target) return false;
        }
        if(sub != (ll)target * target) return false;

        int maskLim = 1 << n;
        for(int mask = 1; mask < maskLim - 1; ++mask) {
            ll sub = 1;

            for(int i = 0; i < n; ++i) {
                if((1 << i) & mask) {
                    sub *= nums[i];
                    if(sub > target) break;
                }
            }
            if(sub == target) return true;
        }

        return false;
    }
};
