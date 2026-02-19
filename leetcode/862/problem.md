# Shortest Subarray with Sum at Least K

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

## Example 1:
Input: nums = [1], k = 1
Output: 1

## Example 2:
Input: nums = [1,2], k = 4
Output: -1

## Example 3:
Input: nums = [2,-1,2], k = 3
Output: 3

## Constraints:
1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

## Thoughts:
nums = [2,-1, 2, 2, 1], k = 3
prefix=[2, 1, 3, 5, 6]

solve: prefix[j] - k >= prefix[i-1]

How do you query the inequality efficiently?
- For each j, there are a few candidates i that satisfy the condition, pick the rightmost i.
- There are a few options: segment tree, multiset and monotone deque/stack
    => Monotone deque/stack because: candidates consumed (not reused).
        Specifically, assume exist an index j' > j and some candidates i that satisfy the condition:
        then j' - i + 1 > j - i + 1. Hence i is "consumed".
