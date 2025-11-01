## 739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

**Example 1:**
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

**Example 2:**
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

**Example 3:**
Input: temperatures = [30,60,90]
Output: [1,1,0]

**Constraints:**
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100

**Thoughts:**
- To get the "waiting days" at i, I need `i` (current day) and `j` (closest warmer day)
- bruteforce: for each `i`, while loop forward to find `j` => O(n^2)
- stack: for each `i`, before push onto the stack, pop out ontop of the stack and update that item if curr > that item.
