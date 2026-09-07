/*
 * 398. Random Pick Index
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 40 ms (beats 79.3%)
 * Memory: 66.9 MB (beats 35.7%)
 * Submitted: 2026-03-27 13:36:39 UTC
 * URL: https://leetcode.com/submissions/detail/1960915564/
 */

class Solution {
    unordered_map<int, vector<int>> freq;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        for(int i = 0; i < nums.size(); ++i) freq[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        if(freq[target].size() <= 1) return freq[target][0];
        
        int randIdx = getRandIdx(0, freq[target].size() - 1);
        return freq[target][randIdx];
    }

    int getRandIdx(int lo, int hi) {
        return rand() % (hi - lo + 1) + lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
