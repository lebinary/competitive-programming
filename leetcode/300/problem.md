# Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

## Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

## Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

## Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

## Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4

## Thoughts:
- Approach 1: DP
  For each num, there are 2 possible choices:
  - include in the subsequence (only if num > prevNum)
  - not include in the subsequence
- Approach 2: Building subsequence intelligently
  - The main problem: when encounter `num` <= max(subsequence), what do we do?
    - cannot just pop the subsequence out until `num` > max(subsequence), that would break the subsequence
    - cannot just ignore, what if the next numbers can build on this one
    => Need a way to still build the curent subsequence, but also open pathway for new subsequence to be built
    => Solution: replace with the first num in subsequence that is >= `num`
