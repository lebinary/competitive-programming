/*
 * 410. Split Array Largest Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.6 MB (beats 43.8%)
 * Submitted: 2025-05-20 12:53:52 UTC
 * URL: https://leetcode.com/submissions/detail/1639297179/
 */

class Solution {
    vector<int> nums;

public:
    int splitArray(vector<int>& nums, int k) {
        this->nums = nums;

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;

        while (l < r) {
            int threshold = (l + r) / 2;

            int isValid = greedyVerifier(threshold, k);

            if(isValid) {
                res = threshold;
                r = threshold;
            } else {
                l = threshold + 1;
            }
        }

        return res;
    }
private:
    bool greedyVerifier(int threshold, int k) {
        int splitCount = 0;
        int currSum = 0;

        for(int num : nums) {
            currSum += num;
            if (currSum > threshold) {
                currSum = num;
                splitCount++;
            }
        }

        return splitCount + 1 <= k;
    }
};
