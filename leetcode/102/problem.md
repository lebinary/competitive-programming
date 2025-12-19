# 102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

## Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

## Example 2:
Input: root = [1]
Output: [[1]]

## Example 3:
Input: root = []
Output: []

## Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

## Thoughts:
- Use a queue, then do BFS by level, i.e:
  given 6 nodes in a binary tree:
      1
     / \
    2   3
   /\    \
  4 5    6

  t=0: q = [1] -> pop 1, insert 2 and 3
  t=1: q = [2, 3] -> pop 2, insert 4, 5
                     pop 3, insert 6
  t=2: q = [4,5,6] -> pop 4,5,6 sequentially
- Analysis: Time O(n)
            Space O(n-1 / 2) = O(n)
