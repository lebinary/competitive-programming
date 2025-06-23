## 57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert `newInterval` into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

**Example 1:**
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

**Example 2:**
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

**Constraints:**
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

**Thoughts**
- There are 4 cases for `newInterval` based on `start` and `end`
  - Start with overlap -> Merge with the closest Start
  - Start with no overalp -> Just insert
  - End with overlap -> Merge with the closest End
  - End with no overlap -> Just insert
- What data structure to use?
  - hashmap<start_i, end_i>
    - Start: Check if index falls between any key and value pair
      -> If yes, overlap, "merge" by getting the key
      -> Else, no overlap, create a new entry in hashmap
    - End: Check if index falls between any key and value pair
      -> If yes, overlap, "merge" by updating the chosen key from Start step, and DELETE the overlapped key
      -> Else, no overlap, use the current End_index
  - 2 passes
    - first pass: get "overlap" index for newStart and newEnd
      - for each start_i and end_i:
        if overlap, start_i <= newStart <= end_i => START = i
        else end_i <= newStart <= start_i+1 => START = i+1
        (do the same for newEnd)
        if start_i <= newEnd <= end_i => END = i
        else end_i <= newEnd <= start_i+1 => END = i+1
- 1 pass:
  - append all intevals with end_i < newStart
  - now there are 3 cases:
    - reached the end: append newInterval and return
    - overlap: append {curr[0], newEnd}
    - no overlap: append {newStart, newEnd}
  - continue with the rest, there are 2 cases:
    - merge: update res[-1][1] value
    - no merge: append as usual
