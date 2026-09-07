/*
 * 1814. Count Nice Pairs in an Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 67 ms (beats 9.2%)
 * Memory: 65.9 MB (beats 6.5%)
 * Submitted: 2026-07-30 13:05:39 UTC
 * URL: https://leetcode.com/submissions/detail/2087515119/
 */

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> delta(n, 0);
        for(int i = 0; i < n; ++i) {
            delta[i] = nums[i] - rev(nums[i]);
        }
        
        unordered_map<int, long long> seen;
        long long pairs = 0;
        for(int x : delta) {
            pairs += seen[x]++;
        }

        return pairs % MOD;
    }

    int rev(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoi(s);
    } 
};


/**
Approach 1: Sliding window
nums = [42,11,1,97]
rev  = [24,11,1,79]

delta= [18,0,0,18]
**/
