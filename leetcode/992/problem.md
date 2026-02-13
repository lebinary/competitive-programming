# 992. Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

## Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

## Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

## Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

## Thoughts:
- Cant do sliding window => not sure when to shrink, i.e k=2 then [1,2,1,2,3] shrink l=0 -> l=3 would discard some valid subarrays like [1,2], [2,1], [1,2,1], [2,1,2]
- Prefix sum? what sum?
  Keep track of frequencies of each key
  freq{int : count}
  Then: freq[i...j] = freq[j] - freq[i-1]
  Example: freq{1:1, 2:1, 3:1} = freq[1:2, 2:2, 3:1] - freq[1:1, 2:1]
  => Would TLE, hashing takes O(n), overall O(n^2)
  => Use a map, not unordered_map, then it takes O(nlogm) where m is the max size of the map

- Keep track of "distinct count" only: prefix[i] = "Count of distinct integers up until index i"
  distinct[i..j] = prefix[j] - prefix[i-1] ? Yes, BUT ONLY WHEN all element in nums[i...j] are distincts, no repeats
