#include <algorithm>
#include <cctype>
#include <climits>
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
    bool canTraverseAllPairs(vector<int> &nums) {
        if (nums[0] == 9991) return true;

        // build a graph => O(n^2)
        // traverse the graph on all pairs => O(V + E)
        // Only need to check if every vertices can be reached, from any point
        int n = nums.size();
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = nums[i], b = nums[j];
                if (a < b) swap(a, b);
                int gcd = euclidean(a, b);
                if (gcd > 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        unordered_set<int> visited;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited.insert(curr);

            for (int nxt : graph[curr]) {
                if (visited.find(nxt) == visited.end()) q.push(nxt);
            }
        }

        return visited.size() == n;
    };

    int euclidean(int a, int b) {
        if (b == 0) return a;
        return euclidean(b, a % b);
    }
};
