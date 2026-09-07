/*
 * 987. Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 4 ms (beats 21.3%)
 * Memory: 15.3 MB (beats 95.4%)
 * Submitted: 2026-04-02 10:15:19 UTC
 * URL: https://leetcode.com/submissions/detail/1966697173/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> sortedRows;

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        int minCol = 0, maxCol = 0;
        
        while(!q.empty()) {
            int n = q.size();

            sortedRows.push_back({});

            for(int i = 0; i < n; ++i) {
                auto [node, r, c] = q.front();
                q.pop();
                
                sortedRows.back().push({node->val, c});

                if(node->left) {
                    q.push({node->left, r + 1, c - 1});
                    minCol = min(minCol, c - 1);
                }

                if(node->right) {
                    q.push({node->right, r + 1, c + 1});
                    maxCol = max(maxCol, c + 1);
                }
            }
        }

        vector<vector<int>> res(maxCol - minCol + 1, vector<int>());
        for(int r = 0; r < sortedRows.size(); ++r) {
            while(!sortedRows[r].empty()) {
                auto [val, c] = sortedRows[r].top();
                sortedRows[r].pop();
                res[c - minCol].push_back(val);
            }
        }

        return res;
    }
};










/**
# Approach 1: DFS/BFS and nested map C++
- Preorder travese the tree, with a tag, insert into nested map[row][col]
- For each row and col:
    sort the row
    append to the res

TC: O(N * logN)
SC: O(nodes)

# Approach 2: BFS by level, sort by row and group by col
- Create a rows array
- BFS by level, for each level:
    insert into the rows
- Traverse each rows:
    sort, then groupBy the col
- Return
TC: O(N + levels * klogk) k < N
SC: O(N)

# Approach 2a: BFS by level, insert into a heap
- TC: O(NlogK) K < N
- SC: O(N)
**/
