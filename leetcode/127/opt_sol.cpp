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
      unordered_set<string> wordSet(wordList.begin(), wordList.end());
      if(wordSet.count(endWord) == 0) return 0;
      int m = wordList[0].size();

      unordered_set<string> front, back;
      unordered_map<string, int> frontDist, backDist;

      front.insert(beginWord);
      back.insert(endWord);
      frontDist[beginWord] = 1;
      backDist[endWord] = 1;

      while(!front.empty() && !back.empty()) {
        if(front.size() > back.size()) {
          swap(front, back);
          swap(frontDist, backDist);
        }

        unordered_set<string> newFront;

        for(string w : front) {
          int dist = frontDist[w];

          for(int i = 0; i < m; ++i) {
            char ch = w[i];

            for(char c = 'a'; c <= 'z'; ++c) {
              if(ch == c) continue;
              w[i] = c;

              if(backDist.count(w)) return dist + backDist[w];
              if(frontDist.count(w) || wordSet.count(w) == 0) continue;

              newFront.insert(w);
              frontDist[w] = dist + 1;
            }

            w[i] = ch;
          }
        }

        swap(front, newFront);
      }

      return 0;
    }
};
