/*
 * 1570. Dot Product of Two Sparse Vectors
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 147 ms (beats 36.0%)
 * Memory: 172.4 MB (beats 49.8%)
 * Submitted: 2026-03-19 08:25:08 UTC
 * URL: https://leetcode.com/submissions/detail/1952839793/
 */

class SparseVector {
public:
    unordered_map<int, int> map;

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                this->map[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(auto it = map.begin(); it != map.end(); it++) {
            if(vec.map.count(it->first)) {
                res += it->second * vec.map[it->first];
            }
        }
        return res;
    }
};
/**
# Ideas: 
- unordered_map, map{index -> nonzero value}
- when calculate dot product, we only care about the SMALLEST SIZE map
    - because only the intersection between 2 maps matters



**/

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
