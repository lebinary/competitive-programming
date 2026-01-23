# 435. Non-overlapping Intervals
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

## Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

## Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

## Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

## Constraints:
1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4

## Thoughts:
- Approach 1: greedy, sort by `starti`, then go through each interval and remove those that overlap with previous
  Time: O(nlogn) = 10^5 log(10^5)
=> might not be correct, if the first item is unsually large:
  example: [[1,10], [2,3], [4,5]] => using approach 1 would remove the 2 instead of 1

- Approach 2: greedy, sort by `endi`, equivalent to "maximizing number of intervals i can pick", which equals "minimize number of intervals to remove"
  example: [[1,10], [2,3], [4,5]]
  sort by end: [[2,3], [4,5], [1,10]]
  last | curr | res
   0      1      0
   1      2      1


- Intuition for "sort by end" vs "sort by start":
  - "Sort by end": take whatever meeting finished first, so that:
    - The room is free sooner for others
    - Number of meetings picked are maximized
    - Number of meetings to be removed are minimized
  - "Sort by start": whatever meeting comes first, process it, so that:
    - Can find the coverage
    - Merge overlapping intervals
