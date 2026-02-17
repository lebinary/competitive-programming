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

// Time taken: 10 m 32 s
// Time taken: 1 hr 28 m 55 s
// Hint used: 2
// Attempt: 2
class Solution {
  public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> res(2, 0);

        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (prizePositions[r] - prizePositions[l] <= k && (r == n - 1 || prizePositions[r + 1] - prizePositions[l] > k)) {
                int len = r - l + 1;
                if (res[0] <= res[1])
                    res[0] = max(res[0], len);
                else
                    res[1] = max(res[1], len);

                l = r + 1;
            }
        }

        return accumulate(res.begin(), res.end(), 0);
    }
};
