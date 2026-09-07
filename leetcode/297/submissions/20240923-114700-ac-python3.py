# 297. Serialize and Deserialize Binary Tree
# Difficulty: Hard
# Status: Accepted
# Runtime: 85 ms (beats 74.8%)
# Memory: 20.4 MB (beats 100.0%)
# Submitted: 2024-09-23 11:47:00 UTC
# URL: https://leetcode.com/submissions/detail/1399515959/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Naive solution
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root: return ""
        res = []
        q = deque([root])

        while q:
            for _ in range(len(q)):
                node = q.popleft()

                if node:
                    res.append(str(node.val))
                    q.append(node.left)
                    q.append(node.right)
                else:
                    res.append("null")

        return ",".join(res)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0 or data == "null": return None

        nodes = data.split(",")

        root = TreeNode(int(nodes[0]))
        q = deque([root])
        i = 1
        
        while q:
            node = q.popleft()

            # left
            if i < len(nodes) and nodes[i] != "null":
                node.left = TreeNode(int(nodes[i]))
                q.append(node.left)
            i += 1
            
            # right
            if i < len(nodes) and nodes[i] != "null":
                node.right = TreeNode(int(nodes[i]))
                q.append(node.right)
            i += 1
        
        return root
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
