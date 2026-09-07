# 297. Serialize and Deserialize Binary Tree
# Difficulty: Hard
# Status: Accepted
# Runtime: 94 ms (beats 31.6%)
# Memory: 22.3 MB (beats 93.7%)
# Submitted: 2026-05-04 18:38:25 UTC
# URL: https://leetcode.com/submissions/detail/1995220713/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
"""
  1
 2 3
4   5 

1 2 3 4 N 5 N


   1
 2   3
    4  5 

1 2 3 N N 4 5

"""
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        encoded = ""

        q = deque([root])
        while q:
            node = q.popleft()

            if node:
                encoded += str(node.val)
                q.append(node.left)
                q.append(node.right)
            else:
                encoded += "N"
            encoded += "|"

        encoded = encoded[:-1]
        return encoded
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        encoded = [int(val) if val != 'N' else None for val in data.split("|")]
        if not encoded or all(val is None for val in encoded):
            return None

        root = TreeNode(encoded[0])

        i = 1
        q = deque([root])

        while q:
            node = q.popleft()

            if i < len(encoded) and encoded[i] != None:
                node.left = TreeNode(encoded[i])
                q.append(node.left)
            i += 1
            
            if i < len(encoded) and encoded[i] != None:
                node.right = TreeNode(encoded[i])
                q.append(node.right)
            i += 1

        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
