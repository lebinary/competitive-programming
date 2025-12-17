## 323. Number of Connected Components in an Undirected Graph
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

## Example 1:
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

## Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

## Constraints:
1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.

## Thoughts:
- Approach 1: use UnionFind
  - create UnionFind data structure size n
  - go through each each and "merge"
  - return unique parents
- Approach 2: traverse graph
  - create an adjacency undirected graph from edges
  - for each node from 0 -> n-1:
    traverse the graph and mark node as "seen", keep count of each component
