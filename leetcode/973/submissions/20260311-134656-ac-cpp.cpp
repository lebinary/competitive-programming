/*
 * 973. K Closest Points to Origin
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 31 ms (beats 76.6%)
 * Memory: 67 MB (beats 78.9%)
 * Submitted: 2026-03-11 13:46:57 UTC
 * URL: https://leetcode.com/submissions/detail/1945039634/
 */

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>> smallestK;

        for(int i = 0; i < n; ++i) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            
            if(smallestK.size() < k) {
                smallestK.push({dist, i});
                continue;
            }

            if(dist >= smallestK.top().first) continue;
            
            smallestK.pop();
            smallestK.push({dist, i});
        }

        vector<vector<int>> res;
        while(!smallestK.empty()) {
            auto [dist, i] = smallestK.top();
            smallestK.pop();
            res.push_back(points[i]);
        }

        return res;
    }
};

/**
Approach 2: max heap
- For each points, store in heap as pair<dist, index>
- If heap.size < k: just insert
- Else:
    if curr >= heap.top: continue
    else:
        heap.pop
        heap << curr
- Return the smallest element in the final k size heap

TC: O(nlogn)
SC: O(k)
**/

