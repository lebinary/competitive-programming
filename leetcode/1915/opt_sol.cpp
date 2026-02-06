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
    long long wonderfulSubstrings(string word) {
        int n = word.size(), m = 'j' - 'a' + 1;
        long long res = 0;
        int bmParity = 0;
        unordered_map<int, long long> map;
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            bmParity ^= (1 << (word[i] - 'a'));

            if (map.count(bmParity)) res += map[bmParity];

            for (int j = 0; j < m; ++j) {
                bmParity ^= (1 << j);
                if (map.count(bmParity)) res += map[bmParity];
                bmParity ^= (1 << j);
            }

            map[bmParity]++;
        }

        return res;
    }
};
