/*
 * 2171. Removing Minimum Number of Magic Beans
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 57 ms (beats 9.8%)
 * Memory: 122.3 MB (beats 6.0%)
 * Submitted: 2026-07-12 11:02:58 UTC
 * URL: https://leetcode.com/submissions/detail/2064901262/
 */

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());

        vector<long long> prefix(n, 0), suffix(n, 0);
        
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            prefix[i] = sum;
            sum += beans[i];
        }

        sum = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(i + 1 < n) {
                sum += (long long)(beans[i + 1] - beans[i]) * (n - i - 1);
                suffix[i] = sum;
            }
        }

        long long res = LLONG_MAX;
        for(int i = 0; i < n; ++i) {
            res = min(res, prefix[i] + suffix[i]);
        }
        return res;
    }
};

// [1, 1, 3, 4] => nullify, reduce both 1's to 0 (total cost = 3) 
// [1, 1, 2, 3] => tie, pick whatever (total cost 3)
// [2, 2, 2, 3] => dont nullify 2, reduce 3's to 2 (total cost = 1)


// [1, 4, 5, 6 ]
// [0, 1, 5, 10]
// [12, 3, 1, 0]

// [1, 4, 5, 8, 10, 16, 17, 25, 27, 35]
//                   |      |


// [1, 5, 10, 18, 28, 44, 61, 86, ., .]
// [., ., .., .., 70, 40, 36, 12, 8, 0]



// [-, -, -, -, -, 16, 16, 16, 16, 16]
// cost = 68
