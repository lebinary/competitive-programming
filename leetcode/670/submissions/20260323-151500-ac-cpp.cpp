/*
 * 670. Maximum Swap
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.3 MB (beats 5.3%)
 * Submitted: 2026-03-23 15:15:01 UTC
 * URL: https://leetcode.com/submissions/detail/1956824097/
 */

class Solution {
public:
    int maximumSwap(int num) {
        string snum = to_string(num);
        int n = snum.size();

        vector<int> suffixMax(n, -1);
        unordered_map<int, int> index;
        int hi = -1;
        for(int i = n - 1; i >= 0; --i) {
            int val = snum[i] - '0';
            hi = max(hi, val);
            suffixMax[i] = hi;
            index[val] = max(index[val], i);
        }

        for(int i = 0; i < n - 1; ++i) {
            if(suffixMax[i + 1] > snum[i] - '0') {
                int swapIdx = index[suffixMax[i+1]];
                swap(snum[i], snum[swapIdx]);
                break;
            }
        }

        return stoi(snum);
    }
};
