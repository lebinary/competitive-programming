# 2583. Kth Largest Sum in a Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 1243 ms (beats 10.4%)
# Memory: 96 MB (beats 93.8%)
# Submitted: 2026-04-30 12:52:14 UTC
# URL: https://leetcode.com/submissions/detail/1991816981/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthLargestLevelSum(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        sums = []

        q = deque([root])

        while q:
            total = 0

            for _ in range(len(q)):
                node = q.popleft()

                total += node.val

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            heapq.heappush(sums, -total)
        
        if len(sums) < k:
            return -1

        i = 1
        while i < k:
            heapq.heappop(sums)
            i += 1
        
        return -sums[0]
        
