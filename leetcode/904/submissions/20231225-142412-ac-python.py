# 904. Fruit Into Baskets
# Difficulty: Medium
# Status: Accepted
# Runtime: 723 ms (beats 5.1%)
# Memory: 18.8 MB (beats 7.1%)
# Submitted: 2023-12-25 14:24:12 UTC
# URL: https://leetcode.com/submissions/detail/1128179407/

class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        res = 0
        l = 0
        total = 0
        count = {}

        for r in range(len(fruits)):
            fruit_type = fruits[r]
            count[fruit_type] = 1 + count.get(fruit_type, 0) 
            total += 1

            while len(count) > 2:
                l_fruit_type = fruits[l]
                count[l_fruit_type] -= 1
                total -= 1
                l += 1

                if count.get(l_fruit_type) == 0:
                    count.pop(l_fruit_type)

            res = max(res, total)
        
        return res
