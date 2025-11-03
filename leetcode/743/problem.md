# 743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

## Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

## Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

## Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

## Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

## Thoughts:
- No more than 100 nodes, positive weight, no duplicate edges => find "shortest path" to all other nodes from one start node `k`
- Sounds like Dijkstra
- But can you solve it without Dijkstra? Yes, do BFS
  - Example; times = [[2,1,1],[2,3,1],[3,4,1]]
    - 1. build adjacentcy graph: graph = {2: [[1,1], [3,1]], 3: [[4, 1]]}
    - 2. BFS by level:
      - first level: q = [(2, 1)], t = 0
      - second level: q = [(1, 1), (3, 1)], t = 1
      - third level: q = [(4, 1)], t = 2
      => return `2`
  - What if edge > 1? i.e graph = {2: [[1,1], [3,2]], 3: [[4, 1]]}
    - do BFS by time, not level:
      - t=0: q = [(2, 1)] (only when weight == 1, allow to move to next node)
      - t=1: q = [(1, 1), (3, 2)]
      - t=2: q = [(3, 1)]
      - t=3: q = [(4, 1)]
      => return `3`
