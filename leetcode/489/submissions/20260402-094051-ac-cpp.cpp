/*
 * 489. Robot Room Cleaner
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 8 ms (beats 56.8%)
 * Memory: 14.5 MB (beats 14.9%)
 * Submitted: 2026-04-02 09:40:51 UTC
 * URL: https://leetcode.com/submissions/detail/1966672387/
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
    unordered_map<string, bool> visited;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    void cleanRoom(Robot& robot) {
        explore(robot, 0, 0, 0);
    }

    string serialize(int r, int c) {
        return to_string(r) + "." + to_string(c);
    }

    void explore(Robot& robot, int r, int c, int d) {
        string key = serialize(r, c);
        if(visited.count(key)) return;
        visited[key] = true;

        robot.clean();
        for(int i = 0; i < 4; ++i) {
            int nd = (d + i) % 4;
            int nr = r + dirs[nd][0], nc = c + dirs[nd][1];
            
            if(robot.move()) {
                explore(robot, nr, nc, nd);
                turnBack(robot);
            }

            robot.turnRight();
        }
    }

    void turnBack(Robot& robot) {
        robot.turnRight(); robot.turnRight();
        robot.move();
        robot.turnRight(); robot.turnRight(); 
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
