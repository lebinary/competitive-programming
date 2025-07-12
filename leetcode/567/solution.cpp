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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);
        int matches = 0;

        for (int i = 0; i < s1.size(); ++i) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }

        // Count initial matches
        for (int i = 0; i < 26; ++i) {
            if (m1[i] == m2[i]) matches++;
        }
        if (matches == 26) return true;

        // Sliding window
        int l = 0;
        for (int r = s1.size(); r < s2.size(); ++r) {
            if (matches == 26) return true;

            int rIdx = s2[r] - 'a';
            m2[rIdx]++;
            if (m1[rIdx] == m2[rIdx])
                matches++;
            else if (m1[rIdx] + 1 == m2[rIdx])
                matches--;

            int lIdx = s2[l] - 'a';
            m2[lIdx]--;
            if (m1[lIdx] == m2[lIdx])
                matches++;
            else if (m1[lIdx] - 1 == m2[lIdx])
                matches--;

            l++;
        }

        return matches == 26;
    }
};
