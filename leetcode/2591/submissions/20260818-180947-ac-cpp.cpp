/*
 * 2591. Distribute Money to Maximum Children
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10 MB (beats 61.3%)
 * Submitted: 2026-08-18 18:09:48 UTC
 * URL: https://leetcode.com/submissions/detail/2111847005/
 */

class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;

        if(money < 0) return -1;
        
        if(money / 7 == children && money % 7 == 0) return children;
        
        if(money / 7 == children - 1 && money % 7 == 3) return children - 2;

        return min(children - 1, money / 7);
    }
};

