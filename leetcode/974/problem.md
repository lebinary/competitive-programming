# 974. Subarray Sums Divisible by K
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

## Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

## Example 2:
Input: nums = [5], k = 9
Output: 0

## Constraints:
1 <= nums.length <= 3 * 10^4
-104 <= nums[i] <= 10^4
2 <= k <= 104

## Thoughts:
- Sliding window? Cant, because expand/shrink can be both improving/worsen result. Example: Assume sum[i..j] % k = 0, its not clear whether expand or shrink
- Prefix sum? Yes, since:
      sum[i...j] = prefix[j] - prefix[i-1]
  =>  sum[i...j] % k = (prefix[j] - prefix[i-1]) % k
  <=> sum[i...j] % k = prefix[j] % k - prefix[i-1] % k
  <=> 0 = prefix[j] % k - prefix[i-1] % k
  <=> prefix[j] % k = prefix[i-1] % k (condition A)
  Rephrase: Count pair (j, i) statisfies *condition A*

  Count algo:
  map={}
  count=0
  for(i = 0; i < n; ++i):
    if(map.hasKey(prefix[i] % k)) count += map[prefix[i] % k]
    map[prefix[i] % k]++
  return count
