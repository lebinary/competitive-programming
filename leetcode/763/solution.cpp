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
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> last;
        vector<int> res;

        for (int i = 0; i < n; ++i) {
            last[s[i]] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i]]);

            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
