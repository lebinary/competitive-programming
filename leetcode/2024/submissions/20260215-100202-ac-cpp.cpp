/*
 * 2024. Maximize the Confusion of an Exam
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 10 ms (beats 46.1%)
 * Memory: 12.5 MB (beats 54.4%)
 * Submitted: 2026-02-15 10:02:02 UTC
 * URL: https://leetcode.com/submissions/detail/1919937819/
 */

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), res = 0;
        int l1 = 0, l2 = 0;
        int count1 = 0, count2 = 0; // count T 

        for(int r = 0; r < n; ++r) {
            if(answerKey[r] == 'T') {
                count1++;
                count2++;
            };

            while(l1 <= r && count1 > k) {
                if(answerKey[l1] == 'T') count1--;
                l1++;
            }
            res = max(res, r - l1 + 1);

            while(l2 <= r && r - l2 + 1 - count2 > k) {
                if(answerKey[l2] == 'T') count2--;
                l2++;
            }
            res = max(res, r - l2 + 1);
        }

        return res;
    }
};
