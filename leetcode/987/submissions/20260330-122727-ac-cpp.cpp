/*
 * 987. Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.4 MB (beats 91.2%)
 * Submitted: 2026-03-30 12:27:28 UTC
 * URL: https://leetcode.com/submissions/detail/1963804406/
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
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> levels;

        struct Data {
            int r;
            int c;
            TreeNode* node; 
        };
        
        queue<Data> q;
        q.push({0, 0, root});
        int minCol = 0, maxCol = 0;

        while(!q.empty()) {
            int k = q.size();
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> level;

            for(int i = 0; i < k; ++i) {
                auto [r, c, node] = q.front();
                q.pop();

                level.push({node->val, c});

                if(node->left) {
                    q.push({r + 1, c - 1, node->left});
                    minCol = min(minCol, c - 1);
                }
                if(node->right) {
                    q.push({r + 1, c + 1, node->right});
                    maxCol = max(maxCol, c + 1);
                }
            }

            levels.push_back(level);
        }

        vector<vector<int>> res(maxCol - minCol + 1, vector<int>());
        for(auto& levelHeap : levels) {
            while(!levelHeap.empty()) {
                auto [val, c] = levelHeap.top();
                levelHeap.pop();
                
                int colIdx = c - minCol;
                res[colIdx].push_back(val);
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
