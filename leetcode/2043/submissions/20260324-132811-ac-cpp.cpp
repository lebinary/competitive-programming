/*
 * 2043. Simple Bank System
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 48.0%)
 * Memory: 123.5 MB (beats 91.7%)
 * Submitted: 2026-03-24 13:28:12 UTC
 * URL: https://leetcode.com/submissions/detail/1957785031/
 */

class Bank {
public:
    vector<long long> balance; 

    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > balance.size() || account2 > balance.size()) return false;
        if(balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > balance.size()) return false;       
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > balance.size()) return false;
        if(balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
