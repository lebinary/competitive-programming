/*
 * 2555. Maximize Win From Two Segments
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 57.0%)
 * Memory: 61.4 MB (beats 74.8%)
 * Submitted: 2026-03-07 19:34:32 UTC
 * URL: https://leetcode.com/submissions/detail/1941138588/
 */

class Solution {
  public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int n = prizePositions.size(), res = 0;
        vector<int> postfixMax(n, 0);

        int r = n - 1;
        for(int l = n - 1; l >= 0; l--) {
            while(prizePositions[r] - prizePositions[l] > k) r--;
            if(l < n - 1) postfixMax[l] = postfixMax[l + 1];
            postfixMax[l] = max(postfixMax[l], r - l + 1);
        }

        int l = 0;
        for(int r = 0; r < n; ++r) {
            while(prizePositions[r] - prizePositions[l] > k) l++;

            int leftSegmentSize = r - l + 1;
            int rightSegmentSize = r < n - 1 ? postfixMax[r + 1] : 0;
            res = max(res, leftSegmentSize + rightSegmentSize);
        }

        return res;
    }
};

/**
Approach 2: postfixMax + sliding window
- precompute postfixMax, where postfixMax[i] = maximum prizes among segments size k
- For each first segment (sliding window):
    res = max(res, first segment's prize + postfixMax[i + 1])
**/
