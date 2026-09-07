/*
 * 55. Jump Game
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 52.3 MB (beats 57.8%)
 * Submitted: 2026-03-12 07:51:59 UTC
 * URL: https://leetcode.com/submissions/detail/1945799854/
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for(int i = 0; i < n; ++i) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};

/**
# Ideas:
- Essentially a shortest path problem: find shortest path from 0 to (n - 1)

# Approach 1: BFS - because weight equals => MLE

# Approach 2: DFS
    dfs(i):
        if i >= n: return false
        if i == n - 1: return true

        res = false
        for(j := i + 1 -> i + nums[i])
            res |= dfs(j)
        return res

# Approach 3: Greedy
- For each i, check against the "Maximum reached" so far:
    - If i > maxReach: the invetervals are disconnected, so cant reach the end
    - Else: can reach the end

**/
