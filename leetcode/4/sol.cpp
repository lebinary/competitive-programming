#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      if(nums1.size() > nums2.size()) swap(nums1, nums2);

      int m = nums1.size(), n = nums2.size();
      int tot = m + n;
      int l = 0, r = m, med = (tot + 1) / 2;

      while(l <= r){
        int m1 = l + (r - l) / 2;
        int m2 = med - m1;

        // left_par = nums1{.., max1} + nums2{..., max2}
        int max1 = m1 > 0 ? nums1[m1 - 1] : INT_MIN;
        int max2 = m2 > 0 ? nums2[m2 - 1] : INT_MIN;

        // right_par = nums1{min1, ...} + nums2{min2, ...}
        int min1 = m1 < m ? nums1[m1] : INT_MAX;
        int min2 = m2 < n ? nums2[m2] : INT_MAX;

        if(max1 <= min2 && max2 <= min1) {
          // we have the correct left_par = nums1[:m1] + nums2[:m2] and right_par = nums1[m1:] + nums2[m2:]
          if(tot % 2 == 1) return max(max1, max2);
          return (max(max1, max2) + min(min1, min2)) / 2.0;
        } else if (max1 > min2) {
          r = m1 - 1; // result: nums[max1] >> right_par in next loop
        } else {
          l = m1 + 1; // result: nums[min1] >> left_par in next loop
        }
      }

      return LLONG_MAX;
    }
};
