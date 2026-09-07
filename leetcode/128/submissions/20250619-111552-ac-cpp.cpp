/*
 * 128. Longest Consecutive Sequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 98 ms (beats 14.5%)
 * Memory: 88.7 MB (beats 76.4%)
 * Submitted: 2025-06-19 11:15:52 UTC
 * URL: https://leetcode.com/submissions/detail/1669337946/
 */


class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int best = 1, n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        for (int num : nums) {
            if (set.empty()) return best;
            if (set.count(num) == 0) continue;
            set.erase(num);

            int count = 1, left = num - 1, right = num + 1;
            while (set.count(left) || set.count(right)) {
                if (set.count(left)) {
                    set.erase(left--);
                    count++;
                }
                if (set.count(right)) {
                    set.erase(right++);
                    count++;
                }
            }

            best = max(best, count);
        }

        return best;
    }
};
