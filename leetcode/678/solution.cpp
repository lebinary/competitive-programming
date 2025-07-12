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
    bool checkValidString(string s) {
        vector<int> st1, st2;
        int n = s.size();

        // '*' acts as '(' in the first pass
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(')
                st1.push_back(i);
            else if (c == '*')
                st2.push_back(i);
            else {
                if (!st1.empty())
                    st1.pop_back();
                else if (!st2.empty())
                    st2.pop_back();
                else
                    return false;
            }
        }

        // '*' acts as ')' in the second pass
        while (!st1.empty() && !st2.empty()) {
            if (st1.back() > st2.back()) return false; // orphan '('
            st1.pop_back();
            st2.pop_back();
        }

        return st1.empty();
    }
};
