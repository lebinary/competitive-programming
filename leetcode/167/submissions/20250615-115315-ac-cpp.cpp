/*
 * 167. Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 19.7 MB (beats 33.6%)
 * Submitted: 2025-06-15 11:53:15 UTC
 * URL: https://leetcode.com/submissions/detail/1664897289/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> map;

        for(int i = 0; i < n; ++i) {
            if(map.find(numbers[i]) != map.end()) return {map[numbers[i]] + 1, i + 1};
            map[target - numbers[i]] = i;
        }

        return {};
    }
};
