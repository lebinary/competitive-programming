# 449. Serialize and Deserialize BST
# Difficulty: Medium
# Status: Accepted
# Runtime: 59 ms (beats 86.8%)
# Memory: 21 MB (beats 99.6%)
# Submitted: 2024-09-22 06:05:38 UTC
# URL: https://leetcode.com/submissions/detail/1398224177/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        if not root: return ""

        res = []
        queue = deque([root])
        while queue:
            for _ in range(len(queue)): 
                node = queue.popleft()
                if node:
                    res.append(str(node.val))
                    queue.append(node.left)
                    queue.append(node.right)
                else:
                    res.append("null")
        return ",".join(res)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if len(data) == 0 or data == "null": return None
        
        nodes = data.split(",")

        root = TreeNode(int(nodes[0]))
        queue = deque([root])
        i = 1
        
        while queue:
            current = queue.popleft()
            if i < len(nodes) and nodes[i] != "null":
                current.left = TreeNode(int(nodes[i]))
                queue.append(current.left)
            i += 1
            
            if i < len(nodes) and nodes[i] != "null":
                current.right = TreeNode(int(nodes[i]))
                queue.append(current.right)
            i += 1

        return root

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
