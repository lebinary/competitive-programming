/*
 * 1871. Jump Game VII
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 7 ms (beats 75.1%)
 * Memory: 23.1 MB (beats 53.2%)
 * Submitted: 2025-05-08 02:51:02 UTC
 * URL: https://leetcode.com/submissions/detail/1628243579/
 */

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;

        int n = s.size();
        queue<int> q;
        q.push(0);
        int farthest = 0;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump + 1, n);

            for (int j = start; j < end; j++) {
                if(s[j] == '0') {
                    q.push(j);

                    if(j == n-1) {
                        return true;
                    };
                }
            }
            farthest = i + maxJump;
        }

        return false;
    }
};
