/*
 * 3562. Maximum Profit from Trading Stocks with Discounts
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1319 ms (beats 5.6%)
 * Memory: 162.8 MB (beats 16.7%)
 * Submitted: 2025-05-27 14:54:55 UTC
 * URL: https://leetcode.com/submissions/detail/1646117699/
 */

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        // 0/1 knapsack problem with graph traversal
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(budget+1)));
        
        // build graph
        vector<vector<int>> graph(n, vector<int>(0));
        for(vector<int>& edge : hierarchy) {
            int parent = edge[0] - 1;
            int child = edge[1] - 1;
            graph[parent].push_back(child);
        };

        dfs(0, present, future, graph, budget, dp);

        vector<int> rootProfits = dp[0][0];
        return *max_element(rootProfits.begin(), rootProfits.end());
    }
private:
    void dfs(int node, vector<int>& present, vector<int>& future, vector<vector<int>>& graph, int budget, vector<vector<vector<int>>>& dp) {
        vector<int> children = graph[node];
        vector<vector<int>> notDiscountChildren;
        vector<vector<int>> discountChildren;

        for(int child : children) {
            dfs(child, present, future, graph, budget, dp);

            notDiscountChildren.push_back(dp[child][0]);
            discountChildren.push_back(dp[child][1]);
        }

        // discount / no discount
        for(int isDiscount = 0; isDiscount < 2; ++isDiscount) {
            vector<int> res(budget + 1);
            int cost = isDiscount ? present[node] / 2 : present[node];
            int profit = future[node] - cost;

            // not buy current node
            // *do 1D knapsack*
            vector<int> base(budget + 1, 0);
            for(vector<int>& child : notDiscountChildren) {
                vector<int> newBase(budget + 1, 0);

                for(int b = 0; b <= budget; ++b) {
                    for(int k = 0; k <= budget - b; ++k) {
                        int totalCost = b + k;
                        int newProfit = base[b] + child[k];
                        newBase[totalCost] = max(newBase[totalCost], newProfit);
                    }
                }
                
                base = newBase;
            }

            // update res
            res = base;

            // buy current node
            if(cost <= budget) {
                // *do 1D knapsack*
                vector<int> base(budget + 1, 0);
                for(vector<int>& child : discountChildren) {
                    vector<int> newBase(budget + 1, 0);

                    for(int b = 0; b <= budget; ++b) {
                        for(int k = 0; k <= budget - b; ++k) {
                            int totalCost = b + k;
                            int newProfit = base[b] + child[k];
                            newBase[totalCost] = max(newBase[totalCost], newProfit);
                        }
                    }

                    base = newBase;
                }

                // update res with new buy
                for(int c = cost; c <= budget; ++c) {
                    res[c] = max(res[c], base[c - cost] + profit);
                }
            }

            dp[node][isDiscount] = res;
        }
    }
};
