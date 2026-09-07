# 96. Unique Binary Search Trees
# Difficulty: Medium
# Status: Accepted
# Runtime: 16 ms (beats 0.5%)
# Memory: 13.3 MB (beats 0.5%)
# Submitted: 2021-10-04 10:51:48 UTC
# URL: https://leetcode.com/submissions/detail/565580543/

"""
Link: https://www.youtube.com/watch?v=Ox0TenN3Zpg
Loop through each value of n and calculate number of possible trees with that n of nodes

Example: n = 4
numTree[4] = numTree[0] * numTree[3]
           + numTree[1] * numTree[2]
           + numTree[2] * numTree[1]
           + numTree[3] * numTree[0]
"""

class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        numTree = [1 for _ in range(n+1)]
        
        for nodes in range(2, n+1):
            total = 0
            for root in range(1, nodes+1):
                #number of nodes to the left side of current root
                left = root - 1
                
                #number of nodes to the right side of current root
                right = nodes - root
                
                total += numTree[left] * numTree[right]
            numTree[nodes] = total
    
        return numTree[n]
