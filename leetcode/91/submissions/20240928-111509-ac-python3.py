# 91. Decode Ways
# Difficulty: Medium
# Status: Accepted
# Runtime: 27 ms (beats 2.2%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-28 11:15:09 UTC
# URL: https://leetcode.com/submissions/detail/1404802768/

class Solution:
    def numDecodings(self, s: str) -> int:
        N = len(s)

        # top down
        dp = {}
        def dfs(i):
            # reached the end
            if i >= N:
                return 1

            # 0 appear at any point, invalid path
            if s[i] == "0":
                return 0

            # path counts after above conditions
            if i == N-1:
                return 1

            if i in dp:
                return dp[i]

            count = dfs(i+1)
            if int(s[i: i+2]) <= 26:
                count += dfs(i+2)

            dp[i] = count
            return count

        return dfs(0)
