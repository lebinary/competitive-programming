# 853. Car Fleet
# Difficulty: Medium
# Status: Accepted
# Runtime: 633 ms (beats 5.0%)
# Memory: 38.6 MB (beats 97.6%)
# Submitted: 2024-09-19 14:06:22 UTC
# URL: https://leetcode.com/submissions/detail/1395479051/

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        combine_data = [(position[i], speed[i]) for i in range(len(position))]
        sorted_data = sorted(combine_data, key=lambda x: x[0], reverse=True)

        latest_time = 0
        res = 0
        for pos, spd in sorted_data:
          curr_time = (target - pos) / spd

          if curr_time > latest_time:
            latest_time = curr_time
            res += 1
        
        return res
