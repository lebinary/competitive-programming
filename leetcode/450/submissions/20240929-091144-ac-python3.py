# 450. Delete Node in a BST
# Difficulty: Medium
# Status: Accepted
# Runtime: 56 ms (beats 2.2%)
# Memory: 19.9 MB (beats 100.0%)
# Submitted: 2024-09-29 09:11:44 UTC
# URL: https://leetcode.com/submissions/detail/1405923378/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return None

        dummy = TreeNode(-1)
        dummy.left = root
        stack = [(dummy, root)]

        while stack:
            (prev, curr) = stack.pop()
            if curr.val == key:
                next_node = None
                if curr.left:
                    next_node = curr.left
                    prev_left, left = None, curr.left
                    while left:
                        prev_left = left
                        left = left.right
                    prev_left.right = curr.right
                elif curr.right:
                    next_node = curr.right

                if prev and prev.left == curr:
                    prev.left = next_node
                elif prev and prev.right == curr:
                    prev.right = next_node
                
            elif curr.val < key:
                if curr.right:
                    stack.append((curr, curr.right))
            else:
                if curr.left:
                    stack.append((curr, curr.left))
        
        return dummy.left

