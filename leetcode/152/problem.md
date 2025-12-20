# 152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

## Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

## Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

## Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

## Thoughts:
- Simplified case: only positive integer and 0 -> expand the window, if reach 0 -> reset
- Complex case: with negative integer, which will "flip" the magnitude, making something negative with large magnitude potentially become the NEW max
  i.e [2, 3, -5, -1, 0, 2, 3]  expected: max = 30 from [2,3,-5,-1]
  for each num:
    keep score of the max_so_far and min_so_far, when see negative number, "flip" it and compare to the max.

- Main takeaway:
  keep a record of a range of [max, min] as you slide through each postiion
  it is NOT guarantee that the range expand monotically, therefore, need to keep track of the "best" value
