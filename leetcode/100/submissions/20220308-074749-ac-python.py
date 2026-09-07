# 100. Same Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 20 ms (beats 0.6%)
# Memory: 13.6 MB (beats 1.2%)
# Submitted: 2022-03-08 07:47:49 UTC
# URL: https://leetcode.com/submissions/detail/655733507/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        
        # Recursive DFS
        if not p and not q: return True

        if p and q and p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) 
            
        return False
        
        
#         #Iterative BFS
#         if not p and not q: return True
#         if not p or not q: return False
#         if p.val != q.val: return False
        
#         p_d = deque([p])
#         q_d = deque([q])
        
#         while p_d and q_d:
#             if len(p_d) != len(q_d): return False
            
#             for i in range(len(p_d)):
#                 p_node = p_d.popleft()
#                 q_node = q_d.popleft()
                
#                 if not p_node or not q_node or p_node.val != q_node.val:
#                     return False

#                 p_d.append(p_node.left)
#                 q_d.append(q_node.left)

#                 p_d.append(p_node.right)
#                 q_d.append(q_node.right)
                    
#         return True
        
