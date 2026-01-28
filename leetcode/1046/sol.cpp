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
    int lastStoneWeight(vector<int> &stones) {
        int n = stones.size();
        if (n == 1) return stones[0];

        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (!maxHeap.empty()) {
            int first = maxHeap.top();
            maxHeap.pop();
            if (maxHeap.empty()) return first;
            int second = maxHeap.top();
            maxHeap.pop();
            if (first == second) continue;
            maxHeap.push(first - second);
        }
        return 0;
    }
};
