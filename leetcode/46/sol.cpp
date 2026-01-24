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
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<int> perm;
        vector<bool> chosen(n, false);
        vector<vector<int>> res;

        dfs(res, nums, perm, chosen);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &perm, vector<bool> &chosen) {
        if (perm.size() >= nums.size()) {
            res.push_back(perm);
            return;
        };

        for (int i = 0; i < nums.size(); ++i) {
            if (chosen[i]) continue;

            chosen[i] = true;
            perm.push_back(nums[i]);
            dfs(res, nums, perm, chosen);
            perm.pop_back();
            chosen[i] = false;
        }
    }
};
