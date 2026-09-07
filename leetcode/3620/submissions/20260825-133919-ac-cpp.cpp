/*
 * 3620. Network Recovery Pathways
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 467 ms (beats 18.1%)
 * Memory: 390.7 MB (beats 17.3%)
 * Submitted: 2026-08-25 13:39:19 UTC
 * URL: https://leetcode.com/submissions/detail/2119694665/
 */

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int m = edges.size(), n = online.size();
        unordered_map<int, vector<vector<int>>> graph;
        long long maxScore = 0;

        for(auto& e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            if(online[u] && online[v]) {
                graph[u].push_back({v, cost});
                maxScore = max(maxScore, (long long)cost);
            }
        }

        long long l = -1, r = maxScore;
        while(l < r) {
            long long mid = r - (r - l) / 2;
            if(validate(graph, m, n, k, mid)) l = mid;
            else r = mid - 1; 
        }

        return l;
    }

    bool validate(auto& graph, int m, int n, long long k, long long score) {
        using Node = tuple<long long, int>;
 
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [totalCost, node] = pq.top();
            pq.pop();

            if(totalCost > dist[node]) continue;           
            dist[node] = min(dist[node], totalCost);

            if(node == n - 1) return true;

            for(auto& vec : graph[node]) {
                int nextNode = vec[0], cost = vec[1];
                long long newTotalCost = totalCost + cost;

                if(cost >= score && newTotalCost < dist[nextNode] && newTotalCost <= k) {
                    pq.push({newTotalCost, nextNode});
                }
            }
        }

        return false;
    }
};

/**
Approach: Binary Search + Dijkstra validator
- Can't use a recursive validator because it cost at least 2^d to reach a node, d is every "diamond"/branching
    0 ──→ a₁ ──┐
     └──→ b₁ ──┴──→ 2 ──→ a₂ ──┐
                     └──→ b₂ ──┴──→ 4 ──→ ...


    => to reach node 4, takes 2^2 paths. Not optimal 
**/
