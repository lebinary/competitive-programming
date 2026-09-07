/*
 * 169. Majority Element
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 28.5 MB (beats 14.7%)
 * Submitted: 2026-03-21 13:08:52 UTC
 * URL: https://leetcode.com/submissions/detail/1954762813/
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
            if(freq[num] > n / 2) return num;
        }
        return INT_MAX;
    }
};
/**
majority element has frequency > round_down(n / 2)
=> the rest element value are < round_up(n / 2)
So the space needed are round_up(n / 2) + 1

# Approach:
- initiate unordered_map
**/
