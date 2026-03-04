#include "sol.cpp"
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    struct TC {
        vector<int> nums;
        int expected;
    };

    vector<TC> tests = {{{3, 1, 2, 4, 5}, 3}, {{1}, 1}};

    Solution sol;
    int pass = 0;

    for (int i = 0; i < tests.size(); ++i) {
        auto &t = tests[i];
        auto got = sol.findMedian(t.nums);
        bool ok = got == t.expected;

        printf("Test %d: ", i);
        if (ok)
            printf("PASS");
        else
            printf("FAIL");
        printf("\n");
    }
}
