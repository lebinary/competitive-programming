# 71. Simplify Path
# Difficulty: Medium
# Status: Accepted
# Runtime: 39 ms (beats 5.7%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-07 15:09:18 UTC
# URL: https://leetcode.com/submissions/detail/1382182868/

class Solution:
    def simplifyPath(self, path: str) -> str:
        path_arr = []

        for curr in path.split("/"):
            curr = curr.replace("/", "")
            if curr == "..":
                if len(path_arr) > 0:
                    path_arr.pop()
                else: 
                    continue
            elif curr == ".":
                continue
            elif len(curr) > 0:
                path_arr.append(curr)
        
        return "/" + "/".join(path_arr)

