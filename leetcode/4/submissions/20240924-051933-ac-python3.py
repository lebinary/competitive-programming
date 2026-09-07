# 4. Median of Two Sorted Arrays
# Difficulty: Hard
# Status: Accepted
# Runtime: 72 ms (beats 5.1%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-24 05:19:33 UTC
# URL: https://leetcode.com/submissions/detail/1400345555/

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # example:
        # [ 2 5 8 9 ] [ 1 3 6 ] --> median = 5 

        # Key insight: find the correct left partition
        # which is [ 1 2 3 5 ]

        # lets say A is small list, B is large list
        # To find it, run binary search on A list
        #   get the left partition on A list
        #   get the left partition on B list
        #   
        #   if A's left partition's max > B's right partition min  
        #       shrink window to the left: r = m - 1
        #       continue
        #
        #   if B's left partition's max > A's right partition min  
        #       shrink window to the right: l = m + 1
        #       continue
        #   
        #   A's left partition's max < B's right partition min
        #       and B's left partition's max < A's right partition min 
        #   -> found the median
        
        # make sure nums1 always the smaller list
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        total = len(nums1) + len(nums2)
        median_idx = (total + 1) // 2

        l = 0
        r = len(nums1)
        while True: # because it is guarantee to have a median
            m1 = l + (r - l) // 2
            m2 = median_idx - m1

            max1 = nums1[m1 - 1] if (m1 - 1) >= 0 else float('-inf')   
            min1 = nums1[m1] if m1 < len(nums1) else float('inf')

            max2 = nums2[m2 - 1] if (m2 - 1) >= 0 else float('-inf')
            min2 = nums2[m2] if m2 < len(nums2) else float('inf')

            if max1 > min2:
                r = m1 - 1
                continue
            
            if max2 > min1:
                l = m1 + 1
                continue

            # found median
            # odd
            if total % 2:
                return max(max1, max2)
            # even
            return (max(max1, max2) + min(min1, min2)) / 2






            

        
