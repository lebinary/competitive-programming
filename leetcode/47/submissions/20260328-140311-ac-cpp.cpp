/*
 * 47. Permutations II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 61.9%)
 * Memory: 11.9 MB (beats 67.9%)
 * Submitted: 2026-03-28 14:03:11 UTC
 * URL: https://leetcode.com/submissions/detail/1961793466/
 */

class Solution {
    vector<vector<int>> res;
    vector<int> perm;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num : nums) freq[num]++;
        dfs(nums, freq, 0);

        return res;
    }

    void dfs(vector<int>& nums, unordered_map<int, int>& freq, int i) {
        if(i >= nums.size()) {
            res.push_back(perm);
            return;
        }

        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if(it->second == 0) continue;

            it->second--;
            perm.push_back(it->first);
            dfs(nums, freq, i + 1);
            perm.pop_back();
            it->second++;
        }
    }
};
