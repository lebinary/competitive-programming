# 946. Validate Stack Sequences
# Difficulty: Medium
# Status: Accepted
# Runtime: 89 ms (beats 10.5%)
# Memory: 13.3 MB (beats 0.3%)
# Submitted: 2024-01-02 10:35:41 UTC
# URL: https://leetcode.com/submissions/detail/1134533452/

class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        stack = []
        
        pop_idx = 0

        for push_idx in range(len(pushed)):
            stack.append(pushed[push_idx])

            while len(stack) > 0 and stack[-1] == popped[pop_idx]:
                stack.pop()
                pop_idx += 1
        
        return len(stack) == 0
        
