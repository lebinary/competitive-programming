/*
 * 135. Candy
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22.8 MB (beats 85.2%)
 * Submitted: 2025-05-24 03:34:46 UTC
 * URL: https://leetcode.com/submissions/detail/1642615235/
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> dis(n, 1);
        int sum = n;

        for(int i = 0; i < n-1; ++i) {
            if(ratings[i+1] > ratings[i]) {
                dis[i+1] = max(dis[i+1], dis[i] + 1);
            }
        }

        for(int i = n-1; i > 0; --i){
            if(ratings[i-1] > ratings[i]) {
                dis[i-1] = max(dis[i-1], dis[i] + 1);
                
            }
        }

        return accumulate(dis.begin(), dis.end(), 0);
    };
};
