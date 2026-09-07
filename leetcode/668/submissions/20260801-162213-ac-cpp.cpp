/*
 * 668. Kth Smallest Number in Multiplication Table
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 11 ms (beats 25.3%)
 * Memory: 7.9 MB (beats 48.8%)
 * Submitted: 2026-08-01 16:22:14 UTC
 * URL: https://leetcode.com/submissions/detail/2090292938/
 */

class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m * n;
    while(lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if(validator(m, n, k, mid)) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }

  bool validator(int m, int n, int k, int x) {
    int eligible = 0;
    for(int i = 1; i <= m; ++i) {
      int y = min(x / i, n);
      eligible += y;
    }

    return eligible >= k;
  }
};

/**
Aproach: Binary Seach + Validator 
Validator:
  for each row i, and value x, eligible elements are all elements with value <= x:
  Let y be the number of eligible elements each row, so:  
    y = min(x/i, n)
  so the validator just need to go through all the rows and accumulate all the y of each row
**/
