# 327. Count of Range Sum

Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

## Example 1:

Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

## Example 2:

Input: nums = [0], lower = 0, upper = 0
Output: 1

## Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
-105 <= lower <= upper <= 105
The answer is guaranteed to fit in a 32-bit integer.

## Thoughts:

- Count pair (i,j) s.t lower <= sum[i..j] <= upper
  => lower <= prefix[j] - prefix[i-1] <= upper
  <=> prefix[j] - upper <= prefix[i-1] <= prefix[j] - lower
- Rephraase problem: count pair (i, j) s.t. satisfy the ABOVE CONDITION

- How to check an inequality CONDITION efficiently? ie. prefix[j] - lower >= prefix[i-1]
  - Use a maxheap for: prefix[j] - lower >= prefix[i-1]
  - Use a minheap for: prefix[j] - upper <= prefix[i-1]
    Pop those on top of both heaps that satisfy BOTH conditions

- Are there more efficient ways, use map
  Use `map` from C++, its already sorted. Then finding the keys satisfy BOTH conditions take O(logn)
  prefix[j] - upper <= prefix[i-1]. `left` = map.lower_bound(prefix[j] - upper)
  prefix[j] - lower >= prefix[i-1]. `right` = map.upper_bound(prefix[j] - lower)
  Theoretically, scanning from `left` to `right` can take O(n) => Overall O(n^2)

- Think of more efficient way solve this, O(log n)
  divide and conquer:
  Let A(nums) be the problem, count pair i,j s.t lower <= sum[i.j] <= upper
  A(nums) = A(nums[:k]) + A(nums[k:]) + A(nums[i:j]) where k = nums.size / 2, i <= nums.size / 2 <= j

  We can figure out A(nums[:k]) & A(nums[k+1:]) recursively

  res = 0
  dfs(nums, i, j):
    if i > j: ret 0
    count = lower <= prefix[j] - prefix[i-1] <= upper
    k = (i + j) / 2
    count += dfs(nums, i, k) + dfs(nums, k, j)
    return count

  dfs2(nums, i, j):
    if i > j: ret 0

    left_half = sort(nums[:k])
    right_half = sort(nums[k:])
    count = 0
    for(j = k; j < n; j++):
      start_i = leftmost_binary_searh(cond: lower <= prefix[j] - prefix[i-1] <= upper)
      end_i = rightmost_binary_search(cond: lower <= prefix[j] - prefix[i-1] <= upper)

      if start_i > end_i: continue
      count += [(end_i - start_i) + 1] * (end_i - start_i)
    ret count
