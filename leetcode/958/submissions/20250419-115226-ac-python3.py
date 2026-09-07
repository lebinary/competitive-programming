# 958. Check Completeness of a Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.8 MB (beats 100.0%)
# Submitted: 2025-04-19 11:52:27 UTC
# URL: https://leetcode.com/submissions/detail/1611447872/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
BFS the tree:

'''

class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False

        q = deque([root])
        seen_null = False
        
        while q:

            for _ in range(len(q)):
                node = q.popleft()

                if not node:
                    seen_null = True
                    continue
                if seen_null:
                    return False
                
                q.append(node.left)
                q.append(node.right)
        return True

        
        
