/*
 * 1101. The Earliest Moment When Everyone Become Friends
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 72 ms (beats 5.3%)
 * Memory: 34.7 MB (beats 5.3%)
 * Submitted: 2026-03-06 12:14:37 UTC
 * URL: https://leetcode.com/submissions/detail/1939798658/
 */

class DSU {
    public:
        vector<int> parent;
        vector<int> size;
        int nSets;

    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        nSets = n;

        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if(parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(size[pu] < size[pv]) swap(pu, pv);
        
        parent[pv] = pu;
        size[pu] += size[pv];
        nSets--;

        return true;
    };
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [&](auto a, auto b){ return a[0] < b[0]; });
        
        int l = -1, r = logs.back()[0];

        if(!validator(logs, n, r)) return -1;
        
        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(logs, n, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<vector<int>> &logs, int n, int cand) {
        DSU *ds = new DSU(n);

        for(int i = 0; i < logs.size(); ++i) {
            int t = logs[i][0], u = logs[i][1], v = logs[i][2];
            if(t > cand) break;
            ds->unionSets(u, v);
        }

        return ds->nSets <= 1;
    }
};

/**
Approach 2: BS + disjoint set
- Sort the logs based on timestamp
- BS on the timestamp
- Validator: go through the sorted logs and build the disjoint set
    if # disjoint set <= 1: return true
    else return false
**/
