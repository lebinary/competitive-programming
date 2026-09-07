/*
 * 2517. Maximum Tastiness of Candy Basket
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 91 ms (beats 5.2%)
 * Memory: 97.8 MB (beats 4.2%)
 * Submitted: 2026-03-08 08:02:23 UTC
 * URL: https://leetcode.com/submissions/detail/1941741783/
 */

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price.front();

        while(l < r) {
            int m = l + (r - l + 1) / 2;
            if(validator(price, k, m)) l = m;
            else r = m - 1;
        }

        return l;
    }

    bool validator(vector<int>& price, int k, int cand) {
        vector<int> bucket;
        bucket.push_back(price[0]);

        for(int i = 0; i < price.size(); ++i) {
            if(price[i] - bucket.back() >= cand) bucket.push_back(price[i]);
            if(bucket.size() >= k) return true;
        }

        return false;
    }
};

/**
# Clarifying:
bucket={x,y,z}
res = min(|x - y|, |y - z|, |x - z|)
assume answer is |x-y|

# Approach:
- sort
- binary search on the tastiness => cand
- validator: form bucket of k s.t all abs diff inside >= cand
    sorted_price = [1,2,5,8,13,21]
    
    bucket = [price[0]]
    for price[i+1] -> price[n-1]:
        if | price - bucket[-1] | >= cand: bucket << price
        if bucker.size >= k: return true
    return false

# Complexity:
TC: O(NlogN + NlogV)
SC: O(k)
**/
