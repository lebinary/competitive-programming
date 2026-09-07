/*
 * 3560. Find Minimum Log Transportation Cost
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.1 MB (beats 0.9%)
 * Submitted: 2025-05-25 02:48:26 UTC
 * URL: https://leetcode.com/submissions/detail/1643592675/
 */

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        long long re = 1;

        if(n > k) {
            if(n % k > 0) re = n % k;
            cost += pow(k, n/k) * re;
        }
        
        if(m > k) {
            if(m % k > 0) re = m % k;
            cost += pow(k, m/k) * re;
        }
        return cost;
    }
};
