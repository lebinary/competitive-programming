# 543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

## Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

## Example 2:
Input: root = [1,2]
Output: 1

## Constraints:
The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

## Thoughts:
- Longest diameter not neccesarily pass through root
       1
      /
     2
    / \
   4   5
  /     \
 6       7
 => 6-4-2-5-7

- At any node, the longest that path that **pass through that node** is: left_height + right_height
- However, it is not guarantee that the path pass through root is the longest, therefore, need to keep track of the maximum path that goes through each node (when it is the root)
