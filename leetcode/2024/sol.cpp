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
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), res = 0;
        int l1 = 0, l2 = 0;
        int count1 = 0, count2 = 0; // count T

        for (int r = 0; r < n; ++r) {
            if (answerKey[r] == 'T') {
                count1++;
                count2++;
            };

            while (l1 <= r && count1 > k) {
                if (answerKey[l1] == 'T') count1--;
                l1++;
            }
            res = max(res, r - l1 + 1);

            while (l2 <= r && r - l2 + 1 - count2 > k) {
                if (answerKey[l2] == 'T') count2--;
                l2++;
            }
            res = max(res, r - l2 + 1);
        }

        return res;
    }
};
