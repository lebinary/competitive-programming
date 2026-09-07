/*
 * 787. Cheapest Flights Within K Stops
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 62.9%)
 * Memory: 17.2 MB (beats 92.8%)
 * Submitted: 2026-01-15 10:58:00 UTC
 * URL: https://leetcode.com/submissions/detail/1885719462/
 */

class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int layer = 0; layer < k + 1; layer++) {
            vector<int> tmp = prices;

            for (vector<int> &edge : flights) {
                int from = edge[0], to = edge[1], cost = edge[2];

                if (prices[from] == INT_MAX) continue;
                tmp[to] = min(tmp[to], prices[from] + cost);
            }

            prices = tmp;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
