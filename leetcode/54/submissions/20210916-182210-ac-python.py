# 54. Spiral Matrix
# Difficulty: Medium
# Status: Accepted
# Runtime: 16 ms (beats 0.5%)
# Memory: 13.4 MB (beats 0.9%)
# Submitted: 2021-09-16 18:22:10 UTC
# URL: https://leetcode.com/submissions/detail/556048492/

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        output = []
        m = len(matrix)
        n = len(matrix[0])
        
        #start positions
        i = 0;
        j = 0;
        
        #Top, right, bottom, left
        boundaryArr = [-1, n, m, -1]
        
        while boundaryArr[2] > boundaryArr[0] and boundaryArr[1] > boundaryArr[3]:
            #Left to right
            for i in range(i, boundaryArr[1]):
                if(len(output) >= m*n): return output
                output.append(matrix[j][i])
            boundaryArr[0] +=1
            j+=1
            
            #Top to bottom
            for j in range(j, boundaryArr[2]):
                if(len(output) >= m*n): return output
                output.append(matrix[j][i])
            boundaryArr[1] -=1
            i-=1
            
            #Right to left
            for i in range(i, boundaryArr[3], -1):
                if(len(output) >= m*n): return output
                output.append(matrix[j][i])
            boundaryArr[2] -=1
            j-=1
            
            #Bottom to top
            for j in range(j, boundaryArr[0], -1):
                if(len(output) >= m*n): return output
                output.append(matrix[j][i])
            boundaryArr[3] +=1
            i+=1
            
        return output;
            
