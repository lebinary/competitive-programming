#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        wordList.push_back(beginWord);
        int n = beginWord.size(), m = wordList.size(), target = -1;
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < m; ++i) {
            if (graph.count(i) == 0) graph[i] = {};
            if (wordList[i] == endWord) target = i;

            for (int j = i + 1; j < m; ++j) {
                if (graph.count(j) == 0) graph[j] = {};

                string &wordA = wordList[i], wordB = wordList[j];
                int diff = 0;
                for (int k = 0; k < n; ++k) {
                    if (wordA[k] != wordB[k]) diff++;
                }
                if (diff == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> q;
        q.push({m - 1, 1});
        vector<bool> visited(m, false);
        visited[m - 1] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (node == target) return dist;

            for (int neiNode : graph[node]) {
                if (visited[neiNode]) continue;

                q.push({neiNode, dist + 1});
                visited[neiNode] = true;
            }
        }

        return 0;
    }
};
