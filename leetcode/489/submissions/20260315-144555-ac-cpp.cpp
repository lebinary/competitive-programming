/*
 * 489. Robot Room Cleaner
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 10 ms (beats 41.9%)
 * Memory: 14.3 MB (beats 23.0%)
 * Submitted: 2026-03-15 14:45:55 UTC
 * URL: https://leetcode.com/submissions/detail/1949182349/
 */

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    unordered_set<string> visited;
    vector<vector<int>> dirs;

    void cleanRoom(Robot& robot) {
        this->dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int r = 0, c = 0, d = 0;
        explore(robot, r, c, d);
    }

    void goBack(Robot& robot) {
        // turn 180
        robot.turnRight(); robot.turnRight();

        // go back
        robot.move();

        // turn 180
        robot.turnRight(); robot.turnRight();
    }

    void explore(Robot& robot, int r, int c, int d) {
        robot.clean();
        visited.insert(serialize(r, c));

        for(int i = 0; i < 4; ++i) {
            int nd = (d + i) % 4;
            int nr = r + dirs[nd][0], nc = c + dirs[nd][1];

            if(!visited.count(serialize(nr, nc)) && robot.move()) {
                explore(robot, nr, nc, nd);
                goBack(robot);
            }

            robot.turnRight();
        }
    }

    string serialize(int r, int c) {
        return to_string(r) + '.' + to_string(c);
    }
};

/** 
# Ideas:
- Case 1: no obstacle
    => explore
- Case 2: has obstacle
    => turn right
=> At each position, "explore" all neighbors

# Approach:
- clean, and mark as visited
- check all 4 directions:
    if can move forward:
        explore
        goback
    turnRight
**/
