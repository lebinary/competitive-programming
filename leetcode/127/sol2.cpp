#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList){
        int source = -1, target = -1;
        for(int i = 0; i < wordList.size(); ++i) {
          if(wordList[i] == endWord) {
            target = i;
          } else if(wordList[i] == beginWord) {
            source = i;
          }
        }
        if(target == -1) return 0;
        if(source == -1) {
          wordList.push_back(beginWord);
          source = wordList.size() - 1;
        }
        if(source == target) return 1;

        int n = wordList.size(), m = wordList[0].size();

        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; ++i) {
          for(int j = i + 1; j < n; ++j) {
            int diff = 0;
            for(int k = 0; k < m; ++k) if(wordList[i][k] != wordList[j][k]) diff++;
            if(diff == 1) {
              graph[i].push_back(j);
              graph[j].push_back(i);
            }
          }
        }

        int dist = 1;
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;

        while(!q.empty()) {
          int qSize = q.size();
          dist++;

          for(int i = 0; i < qSize; ++i) {
            int curr = q.front();
            q.pop();

            for(int nei : graph[curr]) {
              if(visited[nei]) continue;
              if(nei == target) return dist;
              q.push(nei);
              visited[nei] = true;
            }
          }
        }

        return 0;
    }
};
