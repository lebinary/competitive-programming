# 23. Merge k Sorted Lists
# Difficulty: Hard
# Status: Accepted
# Runtime: 19 ms (beats 50.6%)
# Memory: 18.1 MB (beats 79.4%)
# Submitted: 2026-06-13 11:25:42 UTC
# URL: https://leetcode.com/submissions/detail/2031713776/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        window = []
        dummy = ListNode()
        counter = 0

        for head in lists:
            if head:
                heapq.heappush(window, (head.val, counter, head))
                counter += 1

        curr = dummy
        while window:
            _, _, node = heapq.heappop(window)
            
            if node.next:
                heapq.heappush(window, (node.next.val, counter, node.next))
                counter += 1
            
            curr.next = node
            curr = curr.next

        return dummy.next



