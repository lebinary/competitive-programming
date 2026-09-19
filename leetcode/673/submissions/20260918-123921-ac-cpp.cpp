/*
 * 673. Number of Longest Increasing Subsequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 27 ms (beats 72.0%)
 * Memory: 17.5 MB (beats 36.5%)
 * Submitted: 2026-09-18 12:39:21 UTC
 * URL: https://leetcode.com/submissions/detail/2145730641/
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        
        vector<int> len(n, 1), cnt(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 > len[i]) { // found new LIS
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if(len[j] + 1 == len[i]) { // found new "way" to reach LIS
                        cnt[i] += cnt[j];
                    }
                }
            }
        }    
        
        int lis = *max_element(len.begin(), len.end());
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(len[i] == lis) res += cnt[i];
        }

        return res;
    }
};

/**
Approach 1: DP on each starting position and prev position O(n^2)
- For every position i and prev position j, 
    Recurse forward and return the largest strictly increasing subsequence and it's count/freq. 
    Each position i and prev j will have 2 sets of values: 
        If one subsequence is larger than the other, return that set, 
        Else (meaning the 2 sets have equal subsequence length), return the sum of both sets' count

Approach 2: Bottom-up DP
- len[], count[] represent "maximum len, count of that maximum len ending at i"
- for each i, j pair (j < i)
    if nums[j] < nums[i]:
        if len[j] + 1 > len[i]:
            len[i] = len[j] + 1
            count[i] = count[j]
        
        elif len[j] + 1 == len[i]:
            count[i] += count[j]
**/
