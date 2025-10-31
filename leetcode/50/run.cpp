#include "../../print_helpers.h"
#include "opt_solution.cpp"

//  TEST CASES
struct Input {
    double x;
    int n;
};

struct Expected {
    double output;
};

struct TestCase {
    Input input;
    Expected expected;
};

vector<TestCase> testCases = {
    TestCase{Input{2.00000, 10}, Expected{1024.00000}},
    TestCase{Input{2.10000, 3}, Expected{9.26100}},
    TestCase{Input{2.00000, -2}, Expected{0.25000}},
};

//  RUNNER
int main() {
    Solution sol;

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test " << (i + 1) << ": ";

        auto result = sol.myPow(testCases[i].input.x, testCases[i].input.n);
        print(result);

        cout << "Expected: ";
        print(testCases[i].expected.output);
        cout << endl;
    }

    return 0;
}
