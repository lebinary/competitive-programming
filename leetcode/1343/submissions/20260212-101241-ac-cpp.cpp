/*
 * 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 59.3 MB (beats 37.6%)
 * Submitted: 2026-02-12 10:12:42 UTC
 * URL: https://leetcode.com/submissions/detail/1916826000/
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), count = 0, sum = 0;

        for(int r = 0; r < n; ++r) {
            sum += arr[r];
            if(r >= k) sum -= arr[r - k];
            if(r >= k - 1 && sum >= threshold * k) {
                count++;
            }
        }

        return count;
    }
};
