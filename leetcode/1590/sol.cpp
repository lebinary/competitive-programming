#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size();
        int best = n;
        vector<long long> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = -1;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
        }
        if (prefix.back() % p == 0) return 0;

        for (int i = 0; i < n; ++i) {
            int q = remainder(prefix[i] - prefix[n - 1], p);
            if (map.count(q)) best = min(best, i - map[q]);

            int u = remainder(prefix[i], p);
            map[u] = map.count(u) ? max(map[u], i) : i;
        }

        return best == n ? -1 : best;
    }

    int remainder(long long nu, int de) { return ((nu % de) + de) % de; }
};
