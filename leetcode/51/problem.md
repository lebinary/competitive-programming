# 51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

## Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

## Example 2:
Input: n = 1
Output: [["Q"]]

## Constraints:
1 <= n <= 9

## Thoughts:
- Bruteforce approach:
  For each queen, there are n options:
    For each option, the next queen will pick (n - 1) options
      For each...
  => Time complexity: n * (n - 1) * (n - 2) * ... * 2 * 1 = n!
- Optimized approach:
  - Eliminate the diagonal:
    How to check if 2 positions are diagonally aligned? (0, 1) and (1, 0) or (1, 2)
      => if |xa - xb| == |ya - yb| then these 2 points are diagonally aligned
  - Eliminate the column:
    How to check if 2 positions are in the same column? check the y-axis
  - Optimized solution, for queen ith:
    dfs(i):
      if i >= n: return

      for i: 0 -> n-1:
        if "available":
          add position in set
          dfs(i + 1)
          remove position from set
    => Time complexity: n * (n - 3) * (n - 1) * 1
