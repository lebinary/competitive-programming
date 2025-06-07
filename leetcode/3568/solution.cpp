#include <cctype>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    int M;
    int N;
    int L;
    int MASK_END;
    vector<vector<int>> DIRS;
    vector<string> classroom;

  public:
    int minMoves(vector<string> &classroom, int energy) {
        this->M = classroom.size();
        this->N = classroom[0].size();
        this->DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        this->classroom = classroom;

        int startR = -1, startC = -1;
        unordered_map<int, int> lookup;
        int keyIdx = 0;
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    lookup[hash(r, c)] = keyIdx++;
                }
            }
        }

        this->L = lookup.size();
        this->MASK_END = (1 << L) - 1;

        queue<vector<int>> q;
        q.push({startR, startC, energy, 0, 0});

        // these are for optimization based on heuristic
        // 1. if we revisited a cell with the same energy and the same bitmask, but larger distance, dont need to explore that path
        // 2. if we revisited a cell with the same bitmask and the same distance, but smaller energy, dont need to explore that path
        map<vector<int>, int> distances; // map {row, col, energy, bitmask} -> distance
        map<vector<int>, int> energies;

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            int r = curr[0], c = curr[1], e = curr[2], bitmask = curr[3], d = curr[4];

            if (bitmask == MASK_END) return d;
            if (e == 0 && classroom[r][c] != 'R') continue;

            // pruning
            if (distances.find({r, c, e, bitmask}) != distances.end() && distances[{r, c, e, bitmask}] <= d) continue;
            distances[{r, c, e, bitmask}] = d;
            if (energies.find({r, c, bitmask, d}) != energies.end() && energies[{r, c, bitmask, d}] >= e) continue;
            energies[{r, c, bitmask, d}] = e;

            if (classroom[r][c] == 'R') e = energy;

            for (vector<int> dir : DIRS) {
                int nr = r + dir[0], nc = c + dir[1];
                if (!isValid(nr, nc)) continue;

                int newBitmask = bitmask;
                if (classroom[nr][nc] == 'L' && lookup.find(hash(nr, nc)) != lookup.end()) {
                    int keyIdx = lookup[hash(nr, nc)];
                    newBitmask |= 1 << keyIdx;
                }

                q.push({nr, nc, e - 1, newBitmask, d + 1});
            }
        }
        return -1;
    }

    bool isValid(int r, int c) { return r >= 0 && r < M && c >= 0 && c < N && classroom[r][c] != 'X'; }
    int hash(int r, int c) { return r * N + c; }
};
