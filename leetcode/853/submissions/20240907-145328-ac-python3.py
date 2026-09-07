# 853. Car Fleet
# Difficulty: Medium
# Status: Accepted
# Runtime: 647 ms (beats 5.0%)
# Memory: 38.7 MB (beats 97.6%)
# Submitted: 2024-09-07 14:53:28 UTC
# URL: https://leetcode.com/submissions/detail/1382168721/

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        combine_data = [(position[i], speed[i]) for i in range(len(position))]
        sorted_pos_spd = sorted(combine_data, key=lambda x: x[0], reverse=True) 

        stack = []

        for pos, spd in sorted_pos_spd:
            curr_time = (target - pos) / spd
            
            infront_fleet_time = stack[-1] if stack else 0
            if curr_time > infront_fleet_time:
                stack.append(curr_time)
        
        return len(stack)
