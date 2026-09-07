# 70. Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 38 ms (beats 0.5%)
# Memory: 13.8 MB (beats 20.0%)
# Submitted: 2021-10-19 14:11:23 UTC
# URL: https://leetcode.com/submissions/detail/573775391/

"""
Bottom up approach, starting from n back to 0

                         ***
                     *** ***
                 *** *** ***
             *** *** *** ***
         *** *** *** *** ***
dp = [ 8, 5,  3,  2,  1,  1]

loop:
1                    one two
2                one two    
3            one two      
4        one two
5    one two

return one

"""



class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        one = 1
        two = 1
        for i in range(2, n+1):
            temp = one
            one = one + two
            two = temp
        return one
            
        
