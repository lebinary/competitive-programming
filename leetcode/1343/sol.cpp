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
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int n = arr.size(), count = 0, sum = 0;

        for (int r = 0; r < n; ++r) {
            sum += arr[r];
            if (r >= k) sum -= arr[r - k];
            if (r >= k - 1 && sum >= threshold * k) {
                count++;
            }
        }

        return count;
    }
};
