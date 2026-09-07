/*
 * 2591. Distribute Money to Maximum Children
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.1 MB (beats 34.2%)
 * Submitted: 2026-08-15 12:50:25 UTC
 * URL: https://leetcode.com/submissions/detail/2107653434/
 */

class Solution {
public:
    int distMoney(int money, int children) {
        for(int res = min(money / 8, children); res >= 0; --res) {
            int remainMoney = money - res * 8;
            int remainKids = children - res;

            if(remainMoney == 4 && remainKids == 1) continue;
            if(remainMoney < remainKids) continue;
            if(remainMoney > 0 && remainKids == 0) continue;
            
            return res;
        }

        return -1;
    }
};

