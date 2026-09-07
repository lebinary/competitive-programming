# 23. Merge k Sorted Lists
# Difficulty: Hard
# Status: Accepted
# Runtime: 69 ms (beats 12.2%)
# Memory: 20 MB (beats 100.0%)
# Submitted: 2024-09-21 13:35:59 UTC
# URL: https://leetcode.com/submissions/detail/1397435720/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class HeapNode:
    def __init__(self, val, node):
        self.val = val
        self.node = node
    
    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0: return None
        
        dummy = ListNode()
        curr = dummy

        min_heap = [HeapNode(node.val, node) for node in lists if node]
        heapq.heapify(min_heap)

        while min_heap:
            heap_node = heapq.heappop(min_heap)
            min_node = heap_node.node

            curr.next = min_node
            curr = curr.next

            if min_node.next:
                heapq.heappush(min_heap, HeapNode(min_node.next.val, min_node.next))

        return dummy.next

