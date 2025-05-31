#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();

    vector<int> dis(n, 1);
    int sum = n;

    for (int i = 0; i < n - 1; ++i) {
      if (ratings[i + 1] > ratings[i]) {
        dis[i + 1] = max(dis[i + 1], dis[i] + 1);
      }
    }

    for (int i = n - 1; i > 0; --i) {
      if (ratings[i - 1] > ratings[i]) {
        dis[i - 1] = max(dis[i - 1], dis[i] + 1);
      }
    }

    return accumulate(dis.begin(), dis.end(), 0);
  };
};
