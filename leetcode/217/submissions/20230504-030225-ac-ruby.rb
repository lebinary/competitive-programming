# 217. Contains Duplicate
# Difficulty: Easy
# Status: Accepted
# Runtime: 153 ms (beats 5.1%)
# Memory: 224.8 MB (beats 98.7%)
# Submitted: 2023-05-04 03:02:25 UTC
# URL: https://leetcode.com/submissions/detail/944126315/

# @param {Integer[]} nums
# @return {Boolean}
require 'set'

def contains_duplicate(nums)
    set = Set.new
    for num in nums do
        if set.include?(num)
            return true
        else
            set << num
        end
    end
    return false
end
