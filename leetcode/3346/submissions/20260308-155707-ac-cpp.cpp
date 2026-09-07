/*
 * 3346. Maximum Frequency of an Element After Performing Operations I
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 322 ms (beats 28.3%)
 * Memory: 162.1 MB (beats 56.5%)
 * Submitted: 2026-03-08 15:57:08 UTC
 * URL: https://leetcode.com/submissions/detail/1942077016/
 */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        for(int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }

        // iterate over target + binary search
        for(int target = nums.front(); target <= nums.back(); ++target) {
            int ll = 0, rr = 0;

            int l = 0, r = n - 1;
            while(l < r) {
                int m = l + (r - l) / 2;
                if(nums[m] + k >= target) r = m;
                else l = m + 1;
            }
            ll = l;

            l = 0, r = n - 1;
            while(l < r) {
                int m = l + (r - l + 1) / 2;
                if(nums[m] - k <= target) l = m;
                else r = m - 1;
            }
            rr = l;

            // there are 2 cases:
            //  - (r-l+1) <= freq[i] + numOps: valid range too short
            //  - (r-l+1) > freq[i] + numOps: valid range long enough
            res = max(res, min(rr - ll + 1, freq[target] + numOperations));
        }

        return res;
    }
};

/**
# Clarifying:
- perform at most 1 for each i
- BUT: adding 0 is a valid operations => can perform "at most" numOperations
- operation: num => [num - k, num + k]

- [1,4,5] k=1 numOperations=2
    => 2

- [4,6] k=1 numOperations=2
    => 2

- [5,11,20,20] k=9 numOperations=2
    => 3

# Ideas:
- Sort + Iterate + Binary search
    - Sort nums
    - For each num:
        BS the rightmost index j s.t. num[j] - k <= num[i] <= nums[j] + k 
        res = max(res, j - i + 1)
    TC: O(nlogn)

- Sort + Sliding window
    - Sort nums
    - For each num r:
        while num[r] - k > num[l] + k: l++
        if(r - l >= numOperations) res = max(res, r - l + 1) 
    TC: O(nlogn)
Both approaches are wrong, because there is no "anchor" item specified

- Sort + Iterative + Binary Search both sides:
    - Sort nums
    - For each num i:
        - BS leftmost s.t. nums[l] + k <= i
        - BS rightmost s.t. nums[r] - k >= i
        - res = max(res, min(r-l+1, count[i] + numOperations))
            Why? there are 2 bottlenecks:
            - (r-l+1) <= count[i] + numOps: have enough ops but valid range is only (r-l+1)
            - (r-l+1) > count[i] + numOps: range (r - l + 1) is large enough to apply all ops
    TC: O(NlogN + VlogN) => can be very slow if V >> N

**/
