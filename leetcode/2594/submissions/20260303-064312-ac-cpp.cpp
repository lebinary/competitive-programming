/*
 * 2594. Minimum Time to Repair Cars
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 515 ms (beats 5.1%)
 * Memory: 59.4 MB (beats 50.9%)
 * Submitted: 2026-03-03 06:43:13 UTC
 * URL: https://leetcode.com/submissions/detail/1936417267/
 */

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = cars;
        sort(ranks.begin(), ranks.end());

        long long l = 0, r = (long long)ranks.back() * n * n;
        while(l < r) {
            long long m = l + (r - l) / 2;

            if(validator(ranks, n, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<int> &ranks, int n, long long time) {
        int carsLeft = n;

        for(long long r : ranks) {
            long long repair = 0;
            while(r * pow(repair + 1, 2) <= time) repair++;
            carsLeft -= repair;
            if(carsLeft <= 0) return true;
        }

        return false;
    }
};

/**

- BS on the time
- Greedy validator: the lower ranks should get as much cars as possible s.t. 
    cars * minutes <= time 
**/
