# 1367. Linked List in Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 72 ms (beats 5.9%)
# Memory: 17.3 MB (beats 100.0%)
# Submitted: 2024-09-12 05:38:07 UTC
# URL: https://leetcode.com/submissions/detail/1387325086/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if not head:
            return True
        if not root:
            return False
        if self.isSame(head, root):
            return True

        left_sub = self.isSubPath(head, root.left)
        right_sub = self.isSubPath(head, root.right)

        return left_sub or right_sub

    def isSame(self, listnode: Optional[ListNode], treenode: Optional[TreeNode]) -> bool:
        if not listnode:
            return True
        if not treenode:
            return False
        if listnode.val != treenode.val:
            return False

        left_same = self.isSame(listnode.next , treenode.left)
        right_same = self.isSame(listnode.next , treenode.right)

        return left_same or right_same
