/*
 * 307. Range Sum Query - Mutable
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 49 ms (beats 77.7%)
 * Memory: 180.4 MB (beats 79.5%)
 * Submitted: 2026-09-09 08:54:40 UTC
 * URL: https://leetcode.com/submissions/detail/2136116336/
 */

struct Seg {
    int n; vector<int> t;

    Seg(vector<int>& a) : n(a.size()), t(2 * n) {
        copy(a.begin(), a.end(), t.begin() + n);
        for(int i = n - 1; i > 0; --i) t[i] = t[2*i] + t[2*i+1];
    }

    void update(int i, int val) {
        for(t[i += n] = val; i >>= 1;) t[i] = t[2*i] + t[2*i+1];
    }

    int query(int l, int r) { // r is exclusive
        int res = 0;
        
        for(l += n, r += n; l < r; l >>=1, r >>= 1) {
            if(l & 1) res += t[l++];
            if(r & 1) res += t[--r];
        }
        
        return res;
    }
};

class NumArray {
    Seg segTree;
public:
    NumArray(vector<int>& nums) : segTree(nums) {}
    
    void update(int index, int val) {
        segTree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return segTree.query(left, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
