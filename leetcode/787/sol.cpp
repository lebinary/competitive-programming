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
        vector<vector<int>> graph(n, vector<int>(n, -1));

        for (vector<int> &f : flights) {
            int from = f[0], to = f[1], cost = f[2];
            graph[from][to] = cost;
        }

        vector<bool> visited(n, false);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        int res = dfs(n, dp, graph, dst, k, src);
        return res == INT_MAX ? -1 : res;
    }

    int dfs(int n, vector<vector<int>> &dp, vector<vector<int>> &graph, int dst, int stops, int curr) {
        if (curr == dst) return 0;
        if (stops < 0) return INT_MAX;
        if (dp[curr][stops] != -1) return dp[curr][stops];

        int best = INT_MAX;
        for (int nxt = 0; nxt < n; nxt++) {
            if (graph[curr][nxt] == -1) continue;

            int res = dfs(n, dp, graph, dst, stops - 1, nxt);
            if (res != INT_MAX) {
                best = min(best, graph[curr][nxt] + res);
            }
        }

        return dp[curr][stops] = best;
    }
};
