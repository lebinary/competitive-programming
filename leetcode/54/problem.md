## 54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


**Solution 1:** Keep track of current direction, current position, perform this routine until reach the matrix size:
1. add current pos to `res`
2 "look forwardd" to next position, is it "valid":
  a. if invalid, switch direction
  b. else, continue

How to decide the next direction?
  - directions = ['R', 'D', 'L', 'U'] maybe?
  - use modulo to get the next direction, so it can circle back
How to calculate next position?
  - plus (0, 1) for 'R', plus (1, 0) for 'D', plus (0, -1) for 'L', plus (-1, 0) for 'U'
  - maybe store `directions` = [(0,1), (1,0), (0, -1), (-1, 0)]
  - then `nextPos` = `currentPos` + `directions[currentDirection]`
