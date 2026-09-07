/*
 * 1184. Distance Between Bus Stops
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 5 ms (beats 30.4%)
 * Memory: 12.6 MB (beats 22.6%)
 * Submitted: 2026-08-04 08:41:27 UTC
 * URL: https://leetcode.com/submissions/detail/2093708108/
 */

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int fwd = 0, rev = 0;

        int i = start;
        while(i != destination) {
          fwd += distance[i];
          i = (i + 1) % n;
        }

        int j = (((start - 1) % n) + n) % n;
        while(j != destination) {
          rev += distance[j]; 
          j = (((j - 1) % n) + n) % n;
        }
        rev += distance[j];

        return min(fwd, rev);  
    }
};
