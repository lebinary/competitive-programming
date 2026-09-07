/*
 * 1539. Kth Missing Positive Number
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3 ms (beats 6.9%)
 * Memory: 14.5 MB (beats 5.2%)
 * Submitted: 2026-03-25 07:52:52 UTC
 * URL: https://leetcode.com/submissions/detail/1958618584/
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), res = 0;
        unordered_set<int> uniq;
        for(int i = 0; i < n; ++i) {
            if(arr[i] <= n + k) uniq.insert(arr[i]);
        }

        int count = 0;
        for(int i = 1; i <= n + k; ++i) {
            if(!uniq.count(i)) count++;
            if(count == k) {
                res = i;
                break;
            }
        }

        return res;
    }
};

/**
# Approach:
the missing number is in the range of [1, n + k]
- any number that is above this range is invalid => mark them as 0
- scan again, swap number to it correct place
- scan again, pick the kth-0

arr = [2,3,4,7,11], k = 5
- [2,3,4,7,0][0,0,0,0,0]
- [0,2,3,4,0][0,7,0,0,0]
- k = 3, i = n, return n + 3
TC: O(n + k)
SC: O(n + k)

# Approach 1:
- turn arr into unordered_set, scan from 0 -> (n + k);
    increase count if:
        - not in set
        - larger than n + k
    if count == k: break
- return
TC: O(n + k)
SC: O(n)
**/
