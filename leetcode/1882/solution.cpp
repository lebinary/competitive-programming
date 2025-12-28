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
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        int m = tasks.size(), n = servers.size();
        vector<int> ans(m, -1);
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> free;
        for (int i = 0; i < n; ++i) {
            free.push({servers[i], i});
        }

        int j = 0;
        long long t = 0;
        while (j < m) {
            while (!busy.empty() && busy.top()[0] <= t) {
                int i = busy.top()[1];
                free.push({servers[i], i});
                busy.pop();
            }

            while (!free.empty() && j < m && j <= t) {
                int i = free.top()[1];
                free.pop();
                busy.push({t + tasks[j], (long long)i});
                ans[j] = i;
                j++;
            }

            t = free.empty() ? busy.top()[0] : j;
        }

        return ans;
    }
};
