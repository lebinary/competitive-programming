#include "../../print_helpers.h"
#include "greedy_sol.cpp"

//  TEST CASES
struct Input {
    vector<int> nums;
};

struct Expected {
    int output;
};

struct TestCase {
    Input input;
    Expected expected;
};

vector<TestCase> testCases = {
  TestCase{ Input{ vector<int>{2,3,1,1,4} }, Expected{ 2 } },
  TestCase{ Input{ vector<int>{2,3,0,1,4} }, Expected{ 2 } },
  TestCase{ Input{ vector<int>{2,1} }, Expected{ 1 } }
};

//  RUNNER
int main() {
    Solution sol;

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test " << (i + 1) << ": ";

        auto result = sol.jump(testCases[i].input.nums);
        print(result);

        cout << "Expected: ";
        print(testCases[i].expected.output);
        cout << endl;
    }

    return 0;
}
