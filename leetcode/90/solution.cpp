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
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;

        dfs(nums, res, curr, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i) {
        if (i >= nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, res, curr, i + 1);
        curr.pop_back();

        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) j++;
        dfs(nums, res, curr, j);
    }
};
