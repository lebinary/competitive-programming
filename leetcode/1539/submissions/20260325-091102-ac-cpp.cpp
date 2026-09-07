/*
 * 1539. Kth Missing Positive Number
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 13.3 MB (beats 29.2%)
 * Submitted: 2026-03-25 09:11:02 UTC
 * URL: https://leetcode.com/submissions/detail/1958677305/
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = n;

        while(l < r) {
            int m = l + (r - l) / 2;
            if(arr[m] - m - 1 >= k) r = m;
            else l = m + 1;
        }

        return k + l;
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

# Approach 1: Use Set
- turn arr into unordered_set, scan from 0 -> (n + k);
    increase count if:
        - not in set
        - larger than n + k
    if count == k: break
- return
TC: O(n + k)
SC: O(n)

# Approach 2: Greedy
- Insight:
    - if arr doesn't contain any value in range [1, n + k], then the missing value is k
    - if arr contains ONE value in range [1, n + k], then the missing value is k + 1
    - if arr contains TWO value in range [1, n + k], then the missing value is k + 2
    - ...
Initially k = 5  → "I need the 5th missing number"
num=2:  2 <= 5 → k becomes 6   (2 took a slot, target shifts)
num=3:  3 <= 6 → k becomes 7   (3 took a slot, target shifts)
num=4:  4 <= 7 → k becomes 8   (4 took a slot, target shifts)
num=7:  7 <= 8 → k becomes 9   (7 took a slot, target shifts)
num=11: 11 > 9 → break         (11 is past our target, stop)
return 9
TC: O(n)
SC: O(alpha)

# Approach 3: Binary search
- Insight: # missing intergers = arr[i] - (i + 1)
    Consider the positive integers line:
    i+1:  1 2 3 4 _ _ _ 
    arr:  _ 2 3 4 _ _ arr[i]
    => k = arr[i] - (i + 1)
         = 7 - (4 + 1)
         = 2
    Meaning: At i, there are 2 missing intergers

- With this insight, binary search:
    find leftmost position s.t. arr[i] - (i + 1) >= k
    note: l = n is valid, in case like: arr=[1,2,3,4] k=2
**/
