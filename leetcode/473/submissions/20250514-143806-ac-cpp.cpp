/*
 * 473. Matchsticks to Square
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 55 ms (beats 55.8%)
 * Memory: 21.3 MB (beats 17.8%)
 * Submitted: 2025-05-14 14:38:06 UTC
 * URL: https://leetcode.com/submissions/detail/1633805127/
 */

class Solution {
    vector<int> sticks;
    unordered_set<int> visited; 
    int n;
    int target;
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 != 0) return false;

        this->sticks = matchsticks;
        sort(sticks.rbegin(), sticks.rend());

        this->n = matchsticks.size();
        this->target = total / 4;

        return dfs(0, 0, 0);
    }
private:
    bool dfs(int start, int sum, int count) {
        if(sum > target) return false;
        if(count == 4) return visited.size() == n;
        if(sum == target) return dfs(0, 0, count+1);

        for (int i = start; i < n; i++) {
            if(visited.contains(i)) continue;

            visited.insert(i);
            if(dfs(i + 1, sum + sticks[i], count)) return true;
            visited.erase(i);

            if(sum == 0) return false;
        }

        return false;
    }
};
