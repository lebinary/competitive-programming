# 173. Binary Search Tree Iterator
# Difficulty: Medium
# Status: Accepted
# Runtime: 76 ms (beats 5.8%)
# Memory: 22.1 MB (beats 0.5%)
# Submitted: 2021-09-21 14:41:17 UTC
# URL: https://leetcode.com/submissions/detail/558650003/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        self.current = root

    def next(self):
        """
        :rtype: int
        """
        
        #keep going left until you cant
        while self.current is not None:
            self.stack.append(self.current)
            self.current = self.current.left
        
        #cant go left anymore -> pop 
        ans = self.stack.pop()
        self.current = ans.right
        
        return ans.val
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.stack or self.current


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
