/*
 * 528. Random Pick with Weight
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 17 ms (beats 50.7%)
 * Memory: 47 MB (beats 74.0%)
 * Submitted: 2026-02-22 09:35:03 UTC
 * URL: https://leetcode.com/submissions/detail/1927281001/
 */

class Solution {
  public:
    vector<int> prefixSum;

    Solution(vector<int> &w) {
        srand(time(0));
        int n = w.size();
        this->prefixSum.assign(n, 0);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += w[i];
            prefixSum[i] += sum;
        }
    }

    int pickIndex() {
        int target = pseudoRand(1, prefixSum.back());
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

    int pseudoRand(int min, int max) {
        return std::rand() % (max - min + 1) + min;
    }
};
