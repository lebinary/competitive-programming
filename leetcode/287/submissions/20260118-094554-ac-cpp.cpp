/*
 * 287. Find the Duplicate Number
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 65.1 MB (beats 41.7%)
 * Submitted: 2026-01-18 09:45:55 UTC
 * URL: https://leetcode.com/submissions/detail/1888745419/
 */

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;

        while (slow == 0 || fast == 0 || slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int slow2 = 0;
        while (slow == 0 || slow2 == 0 || slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
