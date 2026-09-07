/*
 * 2555. Maximize Win From Two Segments
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 43.0%)
 * Memory: 63.6 MB (beats 21.3%)
 * Submitted: 2026-03-07 08:20:54 UTC
 * URL: https://leetcode.com/submissions/detail/1940594789/
 */

class Solution {
  public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int n = prizePositions.size(), res = 0;
        vector<int> prefixMax(n, 0), postfixMax(n, 0);

        int l = 0;
        for(int r = 0; r < n; ++r) {
            while(prizePositions[r] - prizePositions[l] > k) l++;
            prefixMax[r] = r == 0 ? r - l + 1 : max(prefixMax[r - 1], r - l + 1);
        }

        int r = n - 1;
        for(int l = n - 1; l >= 0; --l) {
            while(prizePositions[r] - prizePositions[l] > k) r--;
            postfixMax[l] = l == n-1? r - l + 1 : max(postfixMax[l + 1], r - l + 1);
        }

        for(int i = 0; i < n; ++i) {
            int leftPartition = prefixMax[i];
            int rightPartition = i == n - 1 ? 0 : postfixMax[i + 1];  
            res = max(res, leftPartition + rightPartition);
        }

        return res;
    }
};

/**
Approach: prefixMax + postfixMax + calculate result

- Sliding window left -> right: 
    keep track of prefixMax[i], max #prizes among segments where nums[r] - nums[l] <= k 
- Sliding window right -> left:
    keep track of postfixMax[i], max #prizes among segments where nums[r] - nums[l] <= k
- For each "parition i":
    res = max(res, prefix[i] + postfix[i+1])
**/
