# 981. Time Based Key-Value Store
# Difficulty: Medium
# Status: Accepted
# Runtime: 598 ms (beats 5.1%)
# Memory: 72.5 MB (beats 35.8%)
# Submitted: 2024-01-07 04:53:41 UTC
# URL: https://leetcode.com/submissions/detail/1139208295/

class TimeMap(object):

    def __init__(self):
        self.store = {}
        

    def set(self, key, value, timestamp):
        """
        :type key: str
        :type value: str
        :type timestamp: int
        :rtype: None
        """
        if self.store.get(key):
            self.store[key].append((timestamp, value))
        else:
            self.store[key] = [(timestamp, value)]
        

    def get(self, key, timestamp):
        """
        :type key: str
        :type timestamp: int
        :rtype: str
        """
        values = self.store.get(key)

        if not values:
            return ""

        l = 0
        r = len(values) - 1
        res = ""

        while l <= r:
            m = (l + r) // 2
            
            (t, v) = values[m]
            if t <= timestamp:
                res = v 
                l = m + 1
            else:
                r = m - 1
        
        return res



        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
