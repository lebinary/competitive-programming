/*
 * 847. Shortest Path Visiting All Nodes
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1764 ms (beats 5.0%)
 * Memory: 130.4 MB (beats 5.0%)
 * Submitted: 2026-03-16 15:18:02 UTC
 * URL: https://leetcode.com/submissions/detail/1950180642/
 */

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), res = INT_MAX;
        queue<vector<int>> q;
        unordered_set<string> visited;

        for(int i = 0; i < n; ++i) {
            q = queue<vector<int>>();
            visited.clear();

            int node = i, board = (1 << i), dist = 0;
            q.push({node, board, dist});
            visited.insert(serialize(node, board));

            while(!q.empty()) {
                auto& front = q.front();
                int node = front[0], board = front[1], dist = front[2];
                q.pop();
                
                if(board == pow(2, n) - 1) {
                    res = min(res, dist);
                    break;
                }

                for(int neiNode : graph[node]) {
                    int newBoard = (1 << neiNode) | board;
                    if(visited.count(serialize(neiNode, newBoard))) continue;
                    
                    q.push({ neiNode, newBoard, dist + 1 });
                    visited.insert(serialize(neiNode, newBoard));
                }
            }
        }

        return res;        
    }

    string serialize(int node, int board) {
        return to_string(node) + "." + to_string(board);
    }
};

/**
# Thoughts:
What state?
    - current node
    - current "state" if the graph
    example: 
        - current node = 1
        - current board: [0,1,0,0]
    
How many states? n * 2^n = 12000 << 10^7

# Approach:
- BFS, where visited is the combine state of {currNode, currBoard}
**/
