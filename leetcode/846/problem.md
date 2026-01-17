# 846. Hand of Straights
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

## Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

## Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

## Constraints:
1 <= hand.length <= 10^4
0 <= hand[i] <= 10^9
1 <= groupSize <= hand.length

## Thoughts:
- Size of `hand` must be multitple of `groupSize`
- Approach1: sort and keep track of latest largest element in each group
  example:
    [1,2,3,6,2,3,4,7,8] -> sorted [1,2,2,3,3,4,6,7,8]
    groups[{3, 3}, {4, 3}, {8, 3}]
    Time: O(nlogn) + O(n * (n / groupSize))
    Space: O(n/groupSize)
    => slow

- Approach2: sort and use minHeap to keep track of the groups
  sorted [1,2,2,3,3,4,6,7,8]
  minHeap: [{2,2}]
  minHeap:
    if top[1] == groupSize: groupCount++ and pop
    if curr num == top[0] + 1
      update the top minHeap
    else:
      push onto the heap
  return groupCount == n / groupSize

  Time: O(nlogn)
  Space: O(n)
