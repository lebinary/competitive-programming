# 1. Two Sum
# Difficulty: Easy
# Status: Accepted
# Runtime: 91 ms (beats 19.2%)
# Memory: 212 MB (beats 84.1%)
# Submitted: 2023-05-06 04:40:02 UTC
# URL: https://leetcode.com/submissions/detail/945291284/

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    map = Hash.new
    nums.each_with_index do |num, index|
        if map.key?(target - num)
            return [map[target - num], index]         
        else
            map[num] = index
        end
    end
end
