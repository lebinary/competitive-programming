/*
 * 528. Random Pick with Weight
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 22 ms (beats 28.2%)
 * Memory: 47 MB (beats 88.5%)
 * Submitted: 2026-03-06 12:57:55 UTC
 * URL: https://leetcode.com/submissions/detail/1939829199/
 */

class Solution {
  public:
    vector<int> prefixSum;
    int n;

    Solution(vector<int> &w) {
        srand(time(nullptr));

        this->n = w.size();
        this->prefixSum.assign(n, 0);

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += w[i];
            prefixSum[i] = sum;
        }
    }

    int pickIndex() {
        int min = 1, max = prefixSum.back();
        int rand = std::rand() % (max - min + 1) + min;

        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(prefixSum[m] >= rand) r = m;
            else l = m + 1;
        }

        return l;
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
