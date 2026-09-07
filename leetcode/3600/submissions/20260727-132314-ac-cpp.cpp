/*
 * 3600. Maximize Spanning Tree Stability with Upgrades
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 317 ms (beats 17.6%)
 * Memory: 248.1 MB (beats 72.6%)
 * Submitted: 2026-07-27 13:23:15 UTC
 * URL: https://leetcode.com/submissions/detail/2083393016/
 */

class DSU {
    vector<int> parent;
    vector<long long> size;
    int nSets;

    public:
    DSU(int _n) {
        nSets = _n;
        parent.resize(_n + 1);
        size.resize(_n + 1);
        for(int i = 0; i <= _n; ++i) {
            parent[i] = i;
            size[i] = i;
        }
    }

    int find(int node) {
        if(node != parent[node]) parent[node] = find(parent[node]);
        return parent[node];
    }

    bool unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(size[pu] < size[pv]) swap(pu, pv);

        nSets--;
        size[pu] += size[pv];
        parent[pv] = pu;

        return true;
    }

    int components() { 
        return nSets;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](auto& a, auto&b) { 
            return tie(a[3], a[2]) > tie(b[3], b[2]);
        });

        // 2 copies of spanning tree in different DS
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        DSU dsu(n);

        int i = 0;

        // insert "must" edges
        while(i < edges.size()) {
            auto& e = edges[i];
            int u = e[0], v = e[1], score = e[2], must = e[3];
            if(!must) break;
            
            if(!dsu.unionNodes(u, v)) return -1; // there is a cycle
            pq.push({score, must});
            i++;
        }

        // insert "non-must" edges
        while(i < edges.size()) {
            if(dsu.components() == 1) break;

            auto& e = edges[i];
            int u = e[0], v = e[1], score = e[2], must = e[3];

            if(dsu.unionNodes(u, v)) {
                pq.push({score, must});
            }
            i++;
        }

        // invalid tree
        if(dsu.components() > 1) return -1;

        // Find max stability
        priority_queue<int, vector<int>, greater<int>> minOptionals;

        while(!pq.empty() && k > 0) {
            auto& el = pq.top();
            int score = el[0], must = el[1];

            if(must) break;
            pq.pop();

            minOptionals.push(score * 2);
            k--;
        }
        return min(minOptionals.empty() ? INT_MAX : minOptionals.top(), pq.empty() ? INT_MAX : pq.top()[0] );
    }
};

/**
Approach 1: Sort edges by strength + Binary Search + Validator
=> BS + Validator is not good fit because the answer space is not monotonic

Approach 2: Sort edges by strength + Heap + Greedy
**/
