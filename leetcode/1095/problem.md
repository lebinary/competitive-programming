## 1095. Find in Mountain Array

You may recall that an array arr is a mountain array if and only if:
- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
  - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

**Example 1:**
Input: mountainArr = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

**Example 2:**
Input: mountainArr = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.

**Constraints:**
3 <= mountainArr.length() <= 10^4
0 <= target <= 10^9
0 <= mountainArr.get(index) <= 10^9

**Thoughts:**
- Mountain array is monotonic => binary search
- Can only perform at most 100 searches, perform binary searches will cost log(10^4) < 100
- Given `m` is the pivot, there are 3 cases:
  - You are on the top of the mountain (mountain[l] < mountain[m] && mountain[m] > mountain[r])
  - You are on the left side of the mountain (mountain[l] < mountain[m] < mountain[r])
  - You are on the right side of the mountain (mountain[l] > mountain[m] > mountain[r])
- Actually, a better approach is to do first search for the top of the mountain first, then the left side, then the right side
- Algorithm:
  1. Find the top of the mountain => O(log(n))
  2. Perform binary search on left side (if applicable) => ~O(log(n/2))
  3. Perform binary search on the right side (if applicable) => ~O(log(n/2))
  => Overall complexity O(log(n)) + O(log(n/2)). Given n <= 10^4, log(n) + 2*log(n/2) ~= 34. < 100.
