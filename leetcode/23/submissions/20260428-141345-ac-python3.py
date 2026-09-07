# 23. Merge k Sorted Lists
# Difficulty: Hard
# Status: Accepted
# Runtime: 9 ms (beats 62.0%)
# Memory: 23.1 MB (beats 29.3%)
# Submitted: 2026-04-28 14:13:46 UTC
# URL: https://leetcode.com/submissions/detail/1990273988/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        window = []
        dummy = ListNode()
        curr = dummy

        counter = 0 # to prevent heap comparing ListNode directly

        for head in lists:
            if head:
                heapq.heappush(window, (head.val, counter, head))
                counter += 1
        
        while window:
            (_, _, node) = heapq.heappop(window)
            
            if node.next:
                heapq.heappush(window, (node.next.val, counter, node.next))
                counter += 1

            curr.next = node

            curr = curr.next

        return dummy.next
