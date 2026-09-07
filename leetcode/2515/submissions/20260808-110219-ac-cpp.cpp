/*
 * 2515. Shortest Distance to Target String in a Circular Array
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 29.8 MB (beats 56.2%)
 * Submitted: 2026-08-08 11:02:19 UTC
 * URL: https://leetcode.com/submissions/detail/2099005044/
 */

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex] == target) return 0;
        
        int n = words.size();

        for(int i = 0; i < n; ++i) {
            int l = (startIndex - i + n) % n;
            int r = (startIndex + i) % n;
            if(l != startIndex && words[l] == target) return i;
            if(r != startIndex && words[r] == target) return i;
        }
        return -1;
    }
};
