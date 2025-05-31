#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// DP TOP-DOWN
class Solution {
public:
  vector<vector<int>> graph;
  vector<int> present;
  vector<int> future;
  vector<vector<vector<int>>> memo;

  int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget) {
    // 0/1 knapsack problem with graph traversal
    this->present = present;
    this->future = future;
    this->memo.resize(n, vector<vector<int>>(budget + 1, vector<int>(2, -1)));

    // build graph
    this->graph.resize(n, vector<int>(0));
    for (vector<int> &edge : hierarchy) {
      int parent = edge[0] - 1;
      int child = edge[1] - 1;
      graph[parent].push_back(child);
    };

    return goNode(0, budget, false);
  };

private:
  int goNode(int node, int budget, bool parentBought) {
    if (budget <= 0) return 0;
    if (memo[node][budget][parentBought] != -1) return memo[node][budget][parentBought];

    int best = 0;

    // not buy
    best = max(best, goChildren(node, budget, false));

    // buy
    int cost = parentBought ? present[node] / 2 : present[node];
    if (budget >= cost) {
      int profit = future[node] - cost;
      best = max(best, goChildren(node, budget - cost, true) + profit);
    }

    memo[node][budget][parentBought] = best;
    return best;
  }

  int goChildren(int node, int budget, bool parentBought) {
    if (budget <= 0 || graph[node].empty()) return 0;

    vector<int> dp(budget + 1, 0);
    for (int child : graph[node]) {
      vector<int> newDP = dp;

      for (int b = 0; b <= budget; ++b) {
        // "b" budget is allocated to this child
        int childProfit = goNode(child, b, parentBought);

        // then "k = budget - b" is the budget available for the rest
        // check each of those cases
        for (int k = b; k <= budget; ++k) {
          newDP[k] = max(newDP[k], dp[k - b] + childProfit);
        }
      }

      dp = newDP;
    }

    return dp[budget];
  }
};
