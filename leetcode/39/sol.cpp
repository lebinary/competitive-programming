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
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> comb;

        dfs(candidates, comb, 0, target, 0);
        return res;
    }

    void dfs(vector<int> &candidates, vector<int> &comb, int total, int target, int i) {
        if (total > target || i >= candidates.size()) return;
        if (total == target) {
            res.push_back(comb);
            return;
        }

        comb.push_back(candidates[i]);
        dfs(candidates, comb, total + candidates[i], target, i);
        comb.pop_back();

        dfs(candidates, comb, total, target, i + 1);
    }
};
