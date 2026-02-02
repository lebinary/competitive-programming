# 441. Arranging Coins
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

## Example 1:
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

## Example 2:
Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.

## Constraints:
1 <= n <= 23^1 - 1

## Thoughts
- n = sum_over_i(i) + r, where i = [1, k]
    = 3(i=3) + 2(i=2) + 1(r)
- Approach: find largest k s.t k(k+1) <= 2n. binary search in range [1, n]:
  k = (l + r) / 2
  check if k(k+1) <= 2n:
    l = k
  else:
    r = k - 1
