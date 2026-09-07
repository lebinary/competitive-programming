/*
 * 217. Contains Duplicate
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 55 ms (beats 77.1%)
 * Memory: 90.8 MB (beats 77.1%)
 * Submitted: 2025-05-03 12:05:50 UTC
 * URL: https://leetcode.com/submissions/detail/1624369159/
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};
