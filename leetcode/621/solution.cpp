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
    int leastInterval(vector<char> &tasks, int n) {
        priority_queue<int> maxHeap;
        queue<vector<int>> q;

        vector<int> tmp = vector<int>(26, 0);
        for (char task : tasks) {
            tmp[task - 'A'] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (tmp[i] > 0) maxHeap.push(tmp[i]);
        }

        int t = 0;
        while (!maxHeap.empty() || !q.empty()) {
            t++;

            if (!maxHeap.empty()) {
                int freq = maxHeap.top();
                maxHeap.pop();
                if (freq > 1) q.push({freq - 1, t + n});
            }

            if (!q.empty() && q.front()[1] == t) {
                int freq = q.front()[0];
                q.pop();
                maxHeap.push(freq);
            }
        }

        return t;
    }
};
