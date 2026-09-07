/*
 * 528. Random Pick with Weight
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 97.1%)
 * Memory: 48.6 MB (beats 5.7%)
 * Submitted: 2026-03-06 14:29:25 UTC
 * URL: https://leetcode.com/submissions/detail/1939908147/
 */

// Time taken: 36m 53s
// Attempts: 2
/**
Approach 2: prefixSum + binary search
- build prefixSum
- pickIndex: return a rand number in [prefix_min, prefix_max]
- BS to find leftmost index s.t. prefixSum[i] >= rand, return the index
**/
class Solution {
  public:
    vector<vector<int>> ranges;
    int n;

    Solution(vector<int> &w) {
        srand(time(nullptr));

        this->n = w.size();
        this->ranges.resize(n);

        int start = 0, end = 0;
        for(int i = 0; i < n; ++i) {
            end = start + w[i] - 1;
            ranges[i] = {start, end};
            start = end + 1;
        }
    }

    int pickIndex() {
        int min = 0, max = ranges.back()[1];
        int rand = std::rand() % (max - min + 1) + min;

        int l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(ranges[m][0] <= rand && rand <= ranges[m][1]) return m;
            else if(ranges[m][1] < rand) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};

/**
example: w = [1,3]
distribution: 1,3,3,3

Approach 1: represet as ranges, binary search
- represent as ranges: [ {0,0}, {1,3} ]
- pickIndex: return a rand number in [0, 3]
- binary search for which ranges the number falls in, retunr the ranges's index

Approach 2: prefixSum + binary search
- build prefixSum
- pickIndex: return a rand number in [prefix_min, prefix_max]
- BS to find leftmost index s.t. prefixSum[i] >= rand, return the index
**/
