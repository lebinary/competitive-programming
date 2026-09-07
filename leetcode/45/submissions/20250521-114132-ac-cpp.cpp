/*
 * 45. Jump Game II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 20.4 MB (beats 99.9%)
 * Submitted: 2025-05-21 11:41:32 UTC
 * URL: https://leetcode.com/submissions/detail/1640249963/
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, l = 0, r = 0;
        while(r < nums.size()-1) {
            int farthest = 0;
            for(int i = l; i <= r; ++i){
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            count++;
        }
        return count;
    }
};
