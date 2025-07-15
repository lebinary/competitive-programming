## 42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

**Example 1:**
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

**Example 2:**
Input: height = [4,2,0,3,2,5]
Output: 9


**Constraints:**
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

**Thoughts:**
- Large constraint => bruteforce probably won't work => Solution must be linear complexity
- Attempt 1: Sliding window
  - Intuition: expand (add water to window), shrink (remove water from window)
  - 2 passess: first pass capture the slope up, then the `height[l:]` is the slope down
  => Cannot work, because we cannot decide to add/remove water when expand/shrink without seing the whole data.
- Attempt 2: Two pointers
  - Intuition: at any given position, to decide the water trapped, we need to know the "global max" on both sides
  - Example: WOLG, assume `max_left` < `max_right`, correspond to height[l] and height[r], and we are at position `i`, where l < i < r.
    Then `water_trapped_at_i` = `max_left` - height[i].
