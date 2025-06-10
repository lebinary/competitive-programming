## Count Partitions With Max-Min Difference at Most K

You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

Return the total number of ways to partition nums under this condition.

Since the answer may be too large, return it modulo 109 + 7.

**Example 1:**
Input: nums = [9,4,1,3,7], k = 4
Output: 6
Explanation:
There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
[[9], [4], [1], [3], [7]]
[[9], [4], [1], [3, 7]]
[[9], [4], [1, 3], [7]]
[[9], [4, 1], [3], [7]]
[[9], [4, 1], [3, 7]]
[[9], [4, 1, 3], [7]]

**Example 2:**
Input: nums = [3,3,4], k = 0
Output: 2
Explanation:
There are 2 valid partitions that satisfy the given conditions:
[[3], [3], [4]]
[[3, 3], [4]]

**Constraints:**
2 <= nums.length <= 5 \* 104
1 <= nums[i] <= 109
0 <= k <= 109

**Thoughts:**
Contribution problem: for each i, we count the "contributions" of it to the overall result

Sample run:
Input: nums = [9,4,1,3,7], k = 4
res = 1;
num | res
-1 | 0
9 | 1
4 | 1
1 | 1 + 1 = 2
3 | 2 + 1 + 1 = 4
7 | 4 + 2 = 6

-> Visualize as decision tree: "res at i = the number of branches at level i => hence the final ressult is the number of leaves"
-> O(n^2)
-> Better than `original_solution`, but still not great, the constraint is huge so we need better solution
