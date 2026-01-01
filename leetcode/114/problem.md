# 114. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

## Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

## Example 2:
Input: root = []
Output: []

## Example 3:
Input: root = [0]
Output: [0]

## Thoughts:
- There are 3 cases:
  Case1:
    1    ->    1
  2             2

  Case2:
    1     ->   1
      3          3

  Case3:
    1      ->  1
   2  3         2
                 3

- **Pseudo:** given root
  flatten(left)
  flatten(right)

  if Case1: move from left to right
  if Case2: stay the same
  if Case3:
    - point left's rightmost node to right (whileloop)
    - move from left to right

- **Analysis:**
  Space: O(1)
  Time: There are 3 cases
    - Right-skewed tree: O(n)
    - Balanced tree: O(nlogn)
      for each level, for each node in level:
        whileloop on left subtree to find the rightmost node -> O(n/2)
        i.e:
          - at level 0: traverse left subtree O(n/2)
          - at level 1: traverse left subtree of 2 nodes O(2 * n/4)
          - at level 2: traverse left subtree of 4 nodes O(4 * n/8)
          - ...
        => Since there are O(logn) levels, and each level does O(n/2) work, the complexity is O(n/2 * logn) ~ O(nlogn)
    - Left-skewed tree: O(n^2)
