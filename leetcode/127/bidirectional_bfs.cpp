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

        unordered_set<int> frontSet, backSet;
        unordered_map<int, int> frontDist, backDist;

        frontSet.insert(source);
        backSet.insert(target);
        frontDist[source] = 1;
        backDist[target] = 1;

        while(!frontSet.empty() && !backSet.empty()) {
          if(frontSet.size() > backSet.size()) {
            swap(frontSet, backSet);
            swap(frontDist, backDist);
          }

          unordered_set<int> newFrontSet;

          for(int node : frontSet) {
            int dist = frontDist[node];

            for(int nei : graph[node]) {
              if(backDist.count(nei)) return dist + backDist[nei];
              if(frontDist.count(nei)) continue;

              newFrontSet.insert(nei);
              frontDist[nei] = dist + 1;
            }
          }

          frontSet = move(newFrontSet);
        }

        return 0;
    }
};
