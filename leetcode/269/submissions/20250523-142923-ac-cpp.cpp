/*
 * 269. Alien Dictionary
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 12.7 MB (beats 21.9%)
 * Submitted: 2025-05-23 14:29:24 UTC
 * URL: https://leetcode.com/submissions/detail/1642211049/
 */

class Solution {
public:
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, bool> visited;
    string res;

    string alienOrder(vector<string>& words) {
        int n = words.size();

        // populate vocab O(n)
        for (const auto& word : words) {
            for (char ch : word) {
                graph[ch];
            }
        }
        
        // build graph O(n)
        for(int i = 0; i < n-1; ++i) {
            string& word1 = words[i], word2 = words[i+1];
            int n = min(word1.size(), word2.size());
            if(word1.substr(0, n) == word2.substr(0, n) && word1.size() > word2.size()) return "";
            
            vector<char> edge = getEdge(word1, word2);
            if(edge.empty()) continue;
            graph[edge[0]].insert(edge[1]);
        }

        // traverse graph, postorder O(v + e)
        for(auto& pair : graph) {
            if(dfs(pair.first)) return "";
        }

        reverse(res.begin(), res.end());
        return res;
    }
private:
    vector<char> getEdge(string& word1, string& word2) {
        for(int i = 0; i < word1.size(); ++i) {
            if(word1[i] != word2[i]) {
                return {word1[i], word2[i]};
            }
        }
        
        return {};
    }

    bool dfs(char node) {
        if(visited.find(node) != visited.end()) return visited[node];

        visited[node] = true;
        for(char next : graph[node]) {
            // contain circle
            if(dfs(next)) return true;
        }
        visited[node] = false;
        
        res.push_back(node);
        return false;
    }
};
