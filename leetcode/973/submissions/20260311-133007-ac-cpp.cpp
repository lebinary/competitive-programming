/*
 * 973. K Closest Points to Origin
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 209 ms (beats 5.0%)
 * Memory: 61.6 MB (beats 99.2%)
 * Submitted: 2026-03-11 13:30:08 UTC
 * URL: https://leetcode.com/submissions/detail/1945024365/
 */

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int p = partition(points, l, r);

            if(p == k) break;
            else if(p < k) l = p + 1;
            else r = p - 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& points, int l, int r) {
        int m = l + (r - l) / 2;
        int dist = pow(points[m][0], 2) + pow(points[m][1], 2);

        swap(points[m], points[r]);
        int pivot = l;
        for(int i = l; i < r; ++i) {
            int currDist = pow(points[i][0], 2) + pow(points[i][1], 2);
            if(currDist < dist) {
                swap(points[pivot], points[i]);
                pivot++;
            } 
        }
        swap(points[pivot], points[r]);

        return pivot;
    }
};

/**
Approach 1: quick select
- pick a pivot, anything smaller goes left, anything larger goes right
- keep doing this until pivot == k, then the result is points[:pivot] 
TC: O(nlon)
SC: O(alpha)
**/

