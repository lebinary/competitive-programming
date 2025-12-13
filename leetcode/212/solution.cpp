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
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int m = board.size(), n = board[0].size();
        unordered_map<char, vector<string>> keyMap;
        unordered_map<string, vector<string>> graph;
        vector<string> res;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                char cha = board[r][c];
                string key = format("{}-{}-{}", cha, r, c);
                keyMap[cha].push_back(key);
                graph[key] = {};

                for (vector<int> dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                    string nKey = format("{}-{}-{}", board[nr][nc], nr, nc);
                    graph[key].push_back(nKey);
                }
            }
        }

        for (string word : words) {
            for (string key : keyMap[word[0]]) {
                unordered_set<string> seen;
                if (dfs(word, graph, seen, 0, key)) {
                    res.push_back(word);
                    break;
                }
            }
        }

        return res;
    }

    bool dfs(string &word, unordered_map<string, vector<string>> &graph, unordered_set<string> &seen, int i, string key) {
        if (i >= word.size()) return true;
        if (!graph.count(key) || seen.count(key) || key[0] != word[i]) return false;

        seen.insert(key);
        for (string nKey : graph[key]) {
            if (dfs(word, graph, seen, i + 1, nKey)) return true;
        }
        seen.erase(key);

        return i == word.size() - 1 ? true : false;
    }
};
