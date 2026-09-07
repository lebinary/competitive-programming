/*
 * 128. Longest Consecutive Sequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 325 ms (beats 5.1%)
 * Memory: 88.8 MB (beats 67.3%)
 * Submitted: 2025-06-19 11:11:41 UTC
 * URL: https://leetcode.com/submissions/detail/1669334412/
 */


class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int best = 1, n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());

        for (int num : nums) {
            cout << num << endl;
            if (set.empty()) return best;
            if (set.count(num) == 0) continue;
            set.erase(num);

            int count = 1, curr = num + 1;
            while (set.count(curr)) {
                set.erase(curr++);
                count++;
            }

            curr = num - 1;
            while (set.count(curr)) {
                set.erase(curr--);
                count++;
            }

            best = max(best, count);
        }

        return best;
    }
};
