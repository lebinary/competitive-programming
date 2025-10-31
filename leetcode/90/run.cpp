#include "../../print_helpers.h"
#include "solution.cpp"

//  TEST CASES
struct Input {
    vector<int> nums;
};

struct Expected {
    vector<vector<int>> output;
};

struct TestCase {
    Input input;
    Expected expected;
};

vector<TestCase> testCases = {
    {{{1, 2, 2}}, {{{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}}}},
    {{{0}}, {{{}, {0}}}},
};

//  RUNNER
int main() {
    Solution sol;

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test " << (i + 1) << ": ";

        auto result = sol.subsetsWithDup(testCases[i].input.nums);
        print(result);

        cout << "Expected: ";
        print(testCases[i].expected.output);
        cout << endl;
    }

    return 0;
}
