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
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        unordered_set<int> good;

        for (vector<int> &t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;

            for (int i = 0; i < 3; i++) {
                if (t[i] == target[i]) good.insert(i);
            }
        }

        return good.size() == 3;
    }
};
