# 23. Merge k Sorted Lists
# Difficulty: Hard
# Status: Accepted
# Runtime: 1179 ms (beats 7.2%)
# Memory: 19.4 MB (beats 100.0%)
# Submitted: 2024-09-21 12:59:52 UTC
# URL: https://leetcode.com/submissions/detail/1397407907/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        merged_list = None

        for l in lists:
            merged_list = self.merge(merged_list, l)
        
        return merged_list


    def merge(self, list1, list2):
        dummy = ListNode(0, None)
        node = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                node.next = list1
                list1 = list1.next
            else:
                node.next = list2
                list2 = list2.next
            node = node.next
        
        node.next = list1 or list2

        return dummy.next
