/*
 * 3413. Maximum Coins From K Consecutive Bags
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 92 ms (beats 81.8%)
 * Memory: 157.9 MB (beats 88.2%)
 * Submitted: 2026-08-04 15:13:54 UTC
 * URL: https://leetcode.com/submissions/detail/2094175102/
 */

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
      int n = coins.size(); 
      long long res = 0;

      sort(coins.begin(), coins.end(), [](auto& a, auto& b) {
        return a[0] < b[0];
      });

      int r = n - 1; 
      long long numCoins = 0;
      for(int l = n - 1; l >= 0; --l) {
        numCoins += ((long long)coins[l][1] - coins[l][0] + 1) * coins[l][2];

        while(l <= r && coins[r][0] - coins[l][0] + 1 > k) {
          numCoins -= ((long long)coins[r][1] - coins[r][0] + 1) * coins[r][2];
          r--;
        }

        if(coins[r][1] - coins[l][0] + 1 <= k) {
          res = max(res, numCoins);
        } else {
          long long diff = coins[r][1] - coins[l][0] + 1 - k;
          res = max(res, numCoins - diff * coins[r][2]);
        }
      }

      int l = 0;
      numCoins = 0;
      for(int r = 0; r < n; ++r) {
        numCoins += ((long long)coins[r][1] - coins[r][0] + 1) * coins[r][2];

        while(l <= r && coins[r][1] - coins[l][1] + 1 > k) {
          numCoins -= ((long long)coins[l][1] - coins[l][0] + 1) * coins[l][2];
          l++;
        }

        if(coins[r][1] - coins[l][0] + 1 <= k) {
          res = max(res, numCoins);
        } else {
          long long diff = coins[r][1] - coins[l][0] + 1 - k;
          res = max(res, numCoins - diff * coins[l][2]); 
        }
      }

      return res;              
    }
};
