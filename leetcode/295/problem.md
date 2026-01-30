# 295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

## Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

## Constraints:
-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.


## Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

## Thoughts:
- Approach 1: 2 heaps
  partition the num into left and right: [left(maxheap) | right(minHeap)]
  then the median is either: max_left or avg(max_left, min_right)
  - [....[max_left] | [min_right] ....]
  Time: insert O(logn), query O(1)
- Approach 2: segment tree
  Main idea: build segement tree on `value range`

  Assume V in [0, 100) be out value range, we can build a frequencies array of values:
  freq = [1, 2, 3, ...]
  let prefixV be the prefixSum(freq):
  prefixV = [1, 3, 6, ...]
  Then the median will be the kth smallest element of the array, assume sorted arr size N, then:
    - if N is odd, need to find (N+1)/2 th smallest
    - if N is even, need to find avg(N/2 th smallest, N/2 + 1 th smallest)
  Once identified kth smallest element, binary search on prefixV to find leftmost i s.t. prefixSum[i] >= k:
  - kth smallest element == "leftmost prefixSum[i] >= k"
  Once found i, return i, note: i is the value
  Time: insert O(logn), query O(logn)
