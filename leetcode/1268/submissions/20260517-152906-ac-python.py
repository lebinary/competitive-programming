# 1268. Search Suggestions System
# Difficulty: Medium
# Status: Accepted
# Runtime: 214 ms (beats 32.4%)
# Memory: 21.6 MB (beats 14.4%)
# Submitted: 2026-05-17 15:29:07 UTC
# URL: https://leetcode.com/submissions/detail/2005657783/

class TrieNode:
    def __init__(self):
        self.children = defaultdict(list)
        self.indices = []
        self.isEnd = False


class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """
        res = []
        root = TrieNode()
        products.sort()
        
        for i, product in enumerate(products):
            node = root
            
            for c in product:
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
                node.indices.append(i)

            node.isEnd = True
        
        for i in range(len(searchWord)):
            node = root
            for c in searchWord[:i + 1]:
                if c not in node.children:
                    node = None
                    break
                node = node.children[c]
            
            if node:
                res.append([products[i] for i in node.indices[:3]])
            else:
                res.append([])

        return res

            


