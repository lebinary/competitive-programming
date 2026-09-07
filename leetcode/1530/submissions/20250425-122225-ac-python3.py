# 1530. Number of Good Leaf Nodes Pairs
# Difficulty: Medium
# Status: Accepted
# Runtime: 63 ms (beats 52.7%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2025-04-25 12:22:26 UTC
# URL: https://leetcode.com/submissions/detail/1617562550/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        res = [0]

        def check_pairs(left_dists, right_dists, distance):
            pair_count = 0 
            for left_dist in left_dists:
                for right_dist in right_dists:
                    if left_dist + right_dist <= distance:
                        pair_count += 1
            return pair_count

        def dfs(node, distance):
            if not node:
                return []
            if not node.left and not node.right:
                return [1]
            
            left_dists = dfs(node.left, distance)
            right_dists = dfs(node.right, distance)

            res[0] += check_pairs(left_dists, right_dists, distance)

            return [dist + 1 for dist in left_dists + right_dists]

        dfs(root, distance)

        return res[0]
