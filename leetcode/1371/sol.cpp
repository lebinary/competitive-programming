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
    int findTheLongestSubstring(string s) {
        int n = s.size(), best = 0;
        vector<int> parity(5, 0);
        unordered_map<int, int> map;
        map[0] = -1;

        for (int j = 0; j < n; ++j) {
            int v = getVowelIdx(s[j]);
            if (v != -1) parity[v] ^= 1;

            int key = hash(parity);
            if (map.count(key))
                best = max(best, j - map[key]);
            else
                map[key] = j;
        }

        return best;
    }

    int hash(vector<int> binVec) {
        int mask = 0;
        for (int d = 0; d < binVec.size(); ++d) {
            mask |= (binVec[d] << d);
        }
        return mask;
    }

    // Generalized hash, pick base as max(possible_values) + 1
    // int hash(vector<int> vec, int base) {
    //     int key = 0;
    //     for (int d = 0; d < vec.size(); ++d) {
    //         key = key * base + vec[d];
    //     }
    //     return key;
    // }

    int getVowelIdx(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        if (c == 'u') return 4;
        return -1;
    }
};
