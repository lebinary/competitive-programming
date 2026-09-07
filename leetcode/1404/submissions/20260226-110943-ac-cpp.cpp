/*
 * 1404. Number of Steps to Reduce a Number in Binary Representation to One
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.1 MB (beats 5.7%)
 * Submitted: 2026-02-26 11:09:43 UTC
 * URL: https://leetcode.com/submissions/detail/1931742488/
 */

class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), steps = 0;

        deque<int> dq;
        for(char c : s) dq.push_back(c - '0');

        while(!(dq.size() == 1 && dq.back() == 1)) {
            if(dq.back() == 1) {
                int remain = 1, i = dq.size() - 1;
                while(remain > 0 && i >= 0) {
                    int val = dq[i] + remain;
                    dq[i] = val % 2;
                    remain = val / 2;
                    i--;
                }
                if(remain > 0) dq.push_front(1);
            } else {
                dq.pop_back();
            }
            steps++;
        }

        return steps;
    }
};

/**
"1101" = 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0
       = 13

"1110" = 14
"0111" = 7

approach 1: convert string to decimal, then simulate until reach result
=> Not gonna work, because can go up to 2^500

approach 2: work with string:
- convert string to deque
- if v[-1] == 1: add one, and go to the right to flip sign if need be
- else: right shift, pop back
return steps
**/
