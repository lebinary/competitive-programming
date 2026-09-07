/*
 * 4. Median of Two Sorted Arrays
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 4 ms (beats 18.8%)
 * Memory: 95.2 MB (beats 42.5%)
 * Submitted: 2026-04-01 15:14:42 UTC
 * URL: https://leetcode.com/submissions/detail/1965956444/
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size();

        int total = m + n;
        int medianSize = (total + 1) / 2;

        int l = 0, r = m; // search "how many elements nums1 contribute to leftPartition"
        while(l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = medianSize - m1;

            int max1 = m1 - 1 >= 0 ? nums1[m1 - 1] : INT_MIN;
            int max2 = m2 - 1 >= 0 ? nums2[m2 - 1] : INT_MIN;

            int min1 = m1 < m ? nums1[m1] : INT_MAX;
            int min2 = m2 < n ? nums2[m2] : INT_MAX;

            if(max1 <= min2 && max2 <= min1) {
                if(total & 1) return max(max1, max2);
                return 0.5 * (max(max1, max2) + min(min1, min2)); 

            } else if(max1 > min2) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
        }

        return -1;
    }
};
