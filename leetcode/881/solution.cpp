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
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;

        int count = 0;
        while (l < r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            count++;
        }
        if (l == r) count++;

        return count;
    }
};
