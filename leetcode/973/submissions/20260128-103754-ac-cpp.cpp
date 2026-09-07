/*
 * 973. K Closest Points to Origin
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 213 ms (beats 5.0%)
 * Memory: 61.7 MB (beats 94.9%)
 * Submitted: 2026-01-28 10:37:55 UTC
 * URL: https://leetcode.com/submissions/detail/1899663393/
 */

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int pivot = partition(points, l, r);

            if (pivot == k) {
                break;
            } else if (pivot < k) {
                l = pivot + 1;
            } else {
                r = pivot - 1;
            }
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>> &points, int l, int r) {
        int m = l + (r - l) / 2;
        int dist = pow(points[m][0], 2) + pow(points[m][1], 2);

        swap(points[m], points[r]);

        int pivot = l;
        for (int i = l; i < r; ++i) {
            int currDist = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (currDist < dist) {
                swap(points[pivot++], points[i]);
            }
        }

        swap(points[pivot], points[r]);
        return pivot;
    }
};

