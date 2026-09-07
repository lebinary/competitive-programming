/*
 * 327. Count of Range Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 309 ms (beats 74.9%)
 * Memory: 172.1 MB (beats 74.7%)
 * Submitted: 2026-02-09 12:20:04 UTC
 * URL: https://leetcode.com/submissions/detail/1913446962/
 */


class Solution {
  public:
    int n, lower, upper;
    vector<int> nums;
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        this->n = nums.size();
        this->lower = lower;
        this->upper = upper;
        this->nums = nums;

        vector<long long> prefix(n + 1, 0);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i + 1] = sum;
        }

        return mergeSort(prefix, 0, n + 1);
    }

    int mergeSort(vector<long long> &prefix, int l, int r) {
        if (r - l <= 1) return 0;
        int m = l + (r - l) / 2;

        int count = mergeSort(prefix, l, m) + mergeSort(prefix, m, r);

        int iStart = l, iEnd = l;
        for (int j = m; j < r; ++j) {
            while (iStart < m && prefix[j] - upper > prefix[iStart]) iStart++;
            while (iEnd < m && prefix[iEnd] <= prefix[j] - lower) iEnd++;
            count += iEnd - iStart;
        }

        inplace_merge(prefix.begin() + l, prefix.begin() + m, prefix.begin() + r);
        return count;
    }
};

