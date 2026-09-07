/*
 * 551. Student Attendance Record I
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.3 MB (beats 54.5%)
 * Submitted: 2026-07-29 10:09:44 UTC
 * URL: https://leetcode.com/submissions/detail/2085957218/
 */

class Solution {
public:
    bool checkRecord(string s) {
        int totalAbsent = 0, lateStreak = 0;
        
        int l = 0, r = 0;
        while(r < s.size()) {
            if(s[r] == 'L') {
                l = r;
                while(r < s.size() && s[r] == 'L') r++;
                lateStreak = r - l;
            } else {
                if(s[r] == 'A') totalAbsent++;
                r++;
            }

            if(totalAbsent >= 2 || lateStreak >= 3) return false;
        }

        return true;
    }
};
