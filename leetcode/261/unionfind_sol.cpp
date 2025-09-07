#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// union by size
class DSU {
  public:
    vector<int> parent;
    vector<int> size;
    int n_sets;

    DSU(int _n) {
        n_sets = _n;
        parent.resize(_n + 1);
        size.resize(_n + 1);
        for (int i = 0; i <= _n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    bool unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // same disjoint set
        if (size[pu] < size[pv]) swap(pu, pv);

        n_sets--;
        size[pu] += size[pv];
        parent[pv] = pu;

        return true;
    }

    int components() { return n_sets; }
};

class Solution {
  public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() > n - 1) return false;

        DSU dsu(n);
        for (auto e : edges) {
            if (!dsu.unionNodes(e[0], e[1])) return false;
        }

        return dsu.components() == 1;
    }
};
