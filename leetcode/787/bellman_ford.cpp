#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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
}
