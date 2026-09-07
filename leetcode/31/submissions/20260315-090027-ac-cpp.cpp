/*
 * 31. Next Permutation
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.6 MB (beats 82.7%)
 * Submitted: 2026-03-15 09:00:27 UTC
 * URL: https://leetcode.com/submissions/detail/1948917085/
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l = n-1, r = n - 1;

        // find pivot
        while(l >= 0) {
            if(l < n - 1 && nums[l] < nums[l + 1]) break;
            l--;
        }

        if(l == -1) { // no pivot, largest possible perm
            sort(nums.begin(), nums.end());
            return;
        };

        // find rightmost r larger than l 
        while(nums[l] >= nums[r]) r--;

        swap(nums[l], nums[r]);
        sort(nums.begin() + l + 1, nums.end());
    }
};

/**
[1,2,3,4] [1,2,4,3] [1,3,2,4] [1,3,4,2] [1,4,2,3] [1,4,3,2] 
[2,1,3,4] [2,1,4,3] [2,3,1,4] [2,3,4,1] [2,4,1,3] [2,4,3,1]
[3,1,2,4] [3,1,4,2] [3,2,1,4] [3,2,4,1] [3,4,1,2] [3,4,2,1]
[4,1,2,3] [4,1,3,2] [4,2,1,3] [4,2,3,1] [4,3,1,2] [4,3,2,1]



example: [0,3,2,5,4,1] -> [0,3,4,1,2,5]

- First, find the "inflection point", here its index = 2  
[0, 3, 2, 5, 4, 1]
          5_
             4_  
    3-  
       2-
                1_
 0-
      
- Once reach inflection point, swap with "rightmost next bigger number" to swap
[0, 3, 4, 5, 2, 1]
          5_
       4_  
    3-  
              2-
                1_
 0-


- Then sort the res
[0, 3, 4, 1, 2, 5]
                5_
       4_  
    3-  
             2-
          1_
 0-

**/
