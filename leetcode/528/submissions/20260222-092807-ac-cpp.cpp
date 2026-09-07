/*
 * 528. Random Pick with Weight
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 282 ms (beats 5.0%)
 * Memory: 48.6 MB (beats 5.7%)
 * Submitted: 2026-02-22 09:28:08 UTC
 * URL: https://leetcode.com/submissions/detail/1927275686/
 */

class Solution {
  public:
    random_device rd;
    vector<int> prefixSum;

    Solution(vector<int> &w) {
        int n = w.size();
        this->prefixSum.assign(n, 0);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            prefixSum[i] += sum;
        }
    }

    int pickIndex() {
        int target = rand(1, prefixSum.back());
        int l = 0, r = prefixSum.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (target <= prefixSum[m])
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    int rand(int min, int max) {
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
};
