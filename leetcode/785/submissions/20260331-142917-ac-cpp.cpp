/*
 * 785. Is Graph Bipartite?
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17.6 MB (beats 39.4%)
 * Submitted: 2026-03-31 14:29:18 UTC
 * URL: https://leetcode.com/submissions/detail/1964934498/
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // 2 colors: 0 and 1

        for(int u = 0; u < n; ++u) {
            if(graph[u].size() == 0 || color[u] != -1) continue;

            queue<int> q;
            q.push(u);
            color[u] = 0;
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int nei : graph[node]) {
                    if(color[nei] == -1) {
                        q.push(nei);
                        color[nei] = !color[node];
                    }
                    else if(color[nei] == color[node]) return false;
                }
            }
        }

        return true;
    }
};

/** Approach:
An undirected graph is bipartite if:
- 2 adjacent nodes have different color
- dont contain odd-length cycle

BFS: for each node, check adjacent node
- if any of them have different color: return false
return true
**/
