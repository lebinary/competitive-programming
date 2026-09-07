/*
 * 323. Number of Connected Components in an Undirected Graph
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1 ms (beats 68.1%)
 * Memory: 16.9 MB (beats 66.8%)
 * Submitted: 2025-12-17 15:02:38 UTC
 * URL: https://leetcode.com/submissions/detail/1858136844/
 */

class UF {
  public:
    vector<int> parents;
    int uniqCount;

    UF(int n) {
        this->parents = vector<int>(n);
        this->uniqCount = n;

        for (int i = 0; i < n; ++i) {
            this->parents[i] = i;
        }
    }

    int find(int i) {
        if (parents[i] == i) return i;
        return find(parents[i]);
    }

    void merge(int i, int j) {
        int ipar = find(i), jpar = find(j);
        if (ipar != jpar) uniqCount--;
        parents[ipar] = jpar;
    }
};

class Solution {
  public:
    int countComponents(int n, vector<vector<int>> &edges) {
        UF *uf = new UF(n);
        for (vector<int> edge : edges) {
            uf->merge(edge[0], edge[1]);
        }

        return uf->uniqCount;
    }
};
