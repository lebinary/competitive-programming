## 239. Sliding Window Maximum

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the `max sliding window`.

**Example 1:**
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


Example 2:
Input: nums = [1], k = 1
Output: [1]

**Constraints:**
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length


**Thoughts**
- Naive solution: calculate max for each window, O(n*k)
- Optimized solution: use max heap, for each iteration:
  1. add new element to the heap
  2. clean up the heap, make sure elements that are not in the window is also not on top of the heap
  3. pop out the max, store it
  4. repeat
  => O(nlogn) closer to O(n) if we do it lazily
- Similar problem: 3578
- Differrent approach: problem is "when a better candidates appear, the current one becomes irrelevant" => Monotonic queue/ Stack
