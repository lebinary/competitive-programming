/*
 * 864. Shortest Path to Get All Keys
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 682 ms (beats 5.1%)
 * Memory: 149.8 MB (beats 5.0%)
 * Submitted: 2025-06-07 10:24:27 UTC
 * URL: https://leetcode.com/submissions/detail/1656464493/
 */

class Solution {
public:
  int shortestPathAllKeys(vector<string> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int startR = -1, startC = -1;
    unordered_map<char, int> lookup;
    int keyIdx = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '@') {
          startR = i;
          startC = j;
        } else if (isKey(grid[i][j])) {
          lookup[grid[i][j]] = keyIdx++;
        }
      }
    }

    int keyCount = lookup.size();
    int MASKEND = (1 << keyCount) - 1;
    map<vector<int>, int> states;

    // The expensive part: O(m * n * k!);
    queue<vector<int>> q;
    q.push({startR, startC, 0, 0});
    while (!q.empty()) {
      vector<int> curr = q.front();
      int r = curr[0], c = curr[1], bitmask = curr[2], d = curr[3];
      q.pop();

      if (bitmask == MASKEND) return d;
      if (states.find({r, c, bitmask}) != states.end() && states[{r, c, bitmask}] <= d) continue;
      states[{r, c, bitmask}] = d;

      for (vector<int> dir : dirs) {
        int nr = r + dir[0], nc = c + dir[1];
        if (!isInGrid(nr, nc, m, n) || grid[nr][nc] == '#') continue;
        if (isLock(grid[nr][nc]) && !canUnlock(grid[nr][nc], bitmask, lookup)) continue;

        // finally check bitmask
        int newBitMask = bitmask;
        if (lookup.find(grid[nr][nc]) != lookup.end()) {
          int keyIdx = lookup[grid[nr][nc]];
          newBitMask |= 1 << keyIdx;
        }
        q.push({nr, nc, newBitMask, d + 1});
      }
    }

    return -1;
  };

  bool isKey(char c) { return isalpha(c) && islower(c); };
  bool isLock(char c) { return isalpha(c) && isupper(c); };
  bool isInGrid(int r, int c, int m, int n) { return r >= 0 && r < m && c >= 0 && c < n; };
  bool canUnlock(char lock, int bitmask, unordered_map<char, int> &lookup) {
    char key = tolower(lock);
    int keyIdx = lookup[key];
    return (bitmask & (1 << keyIdx)) != 0;
  }
};
