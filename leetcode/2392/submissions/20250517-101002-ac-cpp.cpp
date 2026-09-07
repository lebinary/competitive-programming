/*
 * 2392. Build a Matrix With Conditions
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 33 ms (beats 16.5%)
 * Memory: 68.6 MB (beats 11.9%)
 * Submitted: 2025-05-17 10:10:02 UTC
 * URL: https://leetcode.com/submissions/detail/1636277121/
 */

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // build row graph
        vector<vector<int>> rowGraph(k+1, vector<int>());
        for(vector<int> condition : rowConditions) {
            rowGraph[condition[0]].push_back(condition[1]);
        }
        vector<int> rowSort = topologicalSort(rowGraph);
        if(rowSort.empty()) return {};

        // build col graph
        vector<vector<int>> colGraph(k+1, vector<int>());
        for(vector<int> condition : colConditions) {
            colGraph[condition[0]].push_back(condition[1]);
        }
        vector<int> colSort = topologicalSort(colGraph);
        if(colSort.empty()) return {};

        // build matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        vector<int> rowPos(k+1);

        for(int r = 0; r < rowSort.size(); ++r) {
            int val = rowSort[r];
            rowPos[val] = r;
        }

        for(int c = 0; c < colSort.size(); ++c) {
            int val = colSort[c];
            int r = rowPos[val];
            matrix[r][c] = val;
        }

        return matrix;
    }
private:
    vector<int> topologicalSort(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;

        unordered_set<int> visited;
        unordered_set<int> path;

        function<bool(int)> dfs = [&](int i) {
            if(path.count(i)) return false;
            if(visited.count(i)) return true;

            path.insert(i);
            for (int nxt : graph[i]) {
                if(!dfs(nxt)) return false;
            }
            path.erase(i);
            visited.insert(i);
            res.push_back(i);
            return true;
        };
            
        for(int node = 1; node < n; ++node){
            if(!visited.count(node)) {
                if(!dfs(node)) return {};
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
