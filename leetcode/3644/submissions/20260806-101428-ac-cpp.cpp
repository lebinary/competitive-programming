/*
 * 3644. Maximum K to Sort a Permutation
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 22 ms (beats 7.3%)
 * Memory: 152.8 MB (beats 65.2%)
 * Submitted: 2026-08-06 10:14:28 UTC
 * URL: https://leetcode.com/submissions/detail/2096513988/
 */

class Solution {
public:
  int sortPermutation(vector<int>& nums) {
    if(validator(nums, INT_MAX)) return 0;

    int l = 0, r = INT_MAX;
    while(l < r) {
      int m = r - (r - l) / 2;
      if(validator(nums, m)) l = m;
      else r = m - 1;
    }
    return l;
  }

  bool validator(vector<int>& nums, int k) {
    int tot = k;
    for(int i = 0; i < nums.size(); ++i) {
      if(i != nums[i]) {
        tot &= nums[i];
        if(tot != k) return false;
      }
    }
    return true;
  }
};
