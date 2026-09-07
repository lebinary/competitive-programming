/*
 * 1239. Maximum Length of a Concatenated String with Unique Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 51 ms (beats 49.0%)
 * Memory: 10.6 MB (beats 84.8%)
 * Submitted: 2026-03-28 12:59:33 UTC
 * URL: https://leetcode.com/submissions/detail/1961748165/
 */

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> freq(26, 0);
        return dfs(arr, freq, n, 0);
    }

    int dfs(auto& arr, auto& freq, int n, int i) {
        if(i >= n) return 0;

        // no pick
        int res = dfs(arr, freq, n, i + 1);
        
        // pick
        for(char c : arr[i]) freq[c - 'a']++;

        // logic
        int len = getLen(freq);
        if(len != -1) res = max(res, len);
        res = max(res, dfs(arr, freq, n, i + 1));

        // unpick
        for(char c : arr[i]) freq[c - 'a']--;

        return res;
    }

    int getLen(auto& freq) {
        int count = 0;
        for(int f : freq) {
            if(f > 1) return -1;
            count += f;
        }
        return count;
    }
};

/**
Approach:
- For each element in arr:
    2 choices: pick or no pick

    If pick:
        - derive am array size 26
    
        check if current arr can be concatinated
        - scan through the array size 26
            if any freq > 1: invalid
        - if valid:
            update res
return res

TC: O(n^2)
SC: O(alpha)
**/
