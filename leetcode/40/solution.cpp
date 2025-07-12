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
    int n;
    vector<int> candidates;
    int target;
    vector<vector<int>> res;
    vector<int> comb;

  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->n = candidates.size();
        this->target = target;

        dfs(0, 0);
        return res;
    }

    void dfs(int i, int total) {
        cout << i << ":" << total << endl;
        if (total == target) {
            res.push_back(comb);
            return;
        }
        if (i >= n || total > target) return;

        comb.push_back(candidates[i]);
        dfs(i + 1, total + candidates[i]);
        comb.pop_back();

        while (i + 1 < n && candidates[i] == candidates[i + 1]) i++;
        dfs(i + 1, total);
    }
};
