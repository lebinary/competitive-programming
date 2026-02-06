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
        vector<int> parity(m, 0);
        unordered_map<int, long long> map;
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            parity[word[i] - 'a'] ^= 1;

            int key = hash(parity);
            if (map.count(key)) res += map[key];

            for (int j = 0; j < m; ++j) {
                parity[j] ^= 1;
                int tempKey = hash(parity);
                if (map.count(tempKey)) res += map[tempKey];
                parity[j] ^= 1;
            }

            map[key]++;
        }

        return res;
    }

    int hash(vector<int> vec) {
        int key = 0, base = 2;
        for (int d = 0; d < vec.size(); ++d) {
            key = key * 2 + vec[d];
        }
        return key;
    }
};
