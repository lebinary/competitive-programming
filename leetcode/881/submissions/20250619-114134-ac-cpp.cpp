/*
 * 881. Boats to Save People
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 18 ms (beats 53.7%)
 * Memory: 45.9 MB (beats 38.3%)
 * Submitted: 2025-06-19 11:41:35 UTC
 * URL: https://leetcode.com/submissions/detail/1669359263/
 */

class Solution {
  public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;

        int count = 0;
        while (l < r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            count++;
        }
        if (l == r) count++;

        return count;
    }
};
