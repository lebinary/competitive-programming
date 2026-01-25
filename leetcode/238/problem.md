# 238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

## Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

## Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

## Constraints:
2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

## Thoughts:
- For any position i, need to know the prefix product [0, i-1] and postfix product [i+1, n-1]
- Approach:
  first loop, calculate prefix product
  second loop, calculate postfix product
  final loop, get the result
- Formally:
  padding the original arr with 1s on both side
  calculate prefix on nums[1:n+1]
  calculate postfix on nums[1:n+1]
  calculate result: res[i] = prefix[i] + postfix[i+2]
- Approach 2: with O(1) space complexity
  product
  zero_count: there are 3 cases: no zero, 1 zero, more than 1 zero
    no zero: go as usual
    1 zero: at the index of the zero, return product
    >1 zero: return 0

  details:
    first loop, calculate the product, count # of zero
    second loop, calculate the res, where:
      > 1 zero count: res[i] = 0
      no zero: res[i] = product / nums[i]
      just one zero: if j == i ? product : product / nums[i]
