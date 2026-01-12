# 560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

## Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

## Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

## Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7

## Thoughts:
- Sliding window
- Pseudo: nums, k, count = 0, sum = 0
  l := 0
  for `r` := 0 -> n-1:
    add nums[r] to sum

    there are 2 cases:
    case nums[l] >= 0 && k >= 0:
    while l < r && sum > k:
      sum -= nums[l++]

    case nums[l] < 0 && k < 0:
    while l < r && sum < k:
      sum -= nums[l++]

    case nums[l] >= 0 && k < 0:
    while l < r && sum < k:
      sum -= nums[l++]

    case nums[l] < 0 && k < 0:
    while l < r && sum < k:
      sum -= nums[l++]
  ret count
