# 130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

## Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

## Example 2:
Input: board = [["X"]]
Output: [["X"]]

## Thoughts:
- Only traverse betweens 'O' cells
- With a single 'O' cell, it is "captured" if: all 4 directions are 'X' cells
- With more than 1 'O' cell, it is captured if:
  - Surrounded by 'X' cells OR neighboring 'O' cells are surrounded by 'X' cells
- Pseudo:
  - Start from edges, mark any 'O' reachable from edges as invalid
  - Then any 'O' remaining is valid region
