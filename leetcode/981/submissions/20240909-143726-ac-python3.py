# 981. Time Based Key-Value Store
# Difficulty: Medium
# Status: Accepted
# Runtime: 585 ms (beats 5.0%)
# Memory: 73.5 MB (beats 5.8%)
# Submitted: 2024-09-09 14:37:26 UTC
# URL: https://leetcode.com/submissions/detail/1384333298/

class TimeMap:
    def __init__(self):
        self.arr_set = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.arr_set:
            self.arr_set[key] = [(value, timestamp)]
        else:
            self.arr_set[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.arr_set: return ""

        res = ""
        arr = self.arr_set[key]
        l = 0
        r = len(arr) - 1

        while l <= r:
            m = l + (r - l) // 2
            
            val, t = arr[m]
            if timestamp >= t:
                res = val
                l = m + 1
            else:
                r = m - 1

        return res 
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
