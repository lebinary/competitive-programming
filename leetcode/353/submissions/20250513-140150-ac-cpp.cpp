/*
 * 353. Design Snake Game
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 132 ms (beats 25.5%)
 * Memory: 86.2 MB (beats 23.5%)
 * Submitted: 2025-05-13 14:01:51 UTC
 * URL: https://leetcode.com/submissions/detail/1632868050/
 */

class SnakeGame {
    set<vector<int>> snakeS;
    queue<vector<int>> snakeQ;
    vector<vector<int>> food;
    int foodIdx;
    int score;
    int width;
    int height;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->foodIdx = 0;
        this->food = food;
        this->score = 0; 
        this->width = width;
        this->height = height;

        vector<int> startPos = {0, 0};
        snakeQ.push(startPos);
        snakeS.insert(startPos);
    }
    
    int move(string direction) {
        vector<int> pos = snakeQ.back();

        if(direction == "U") pos[0]--;
        else if(direction == "D") pos[0]++;
        else if(direction == "L") pos[1]--;
        else pos[1]++;

        // out of bound or touch the snake?
        if(pos[0] < 0 || pos[0] >= height || pos[1] < 0 || pos[1] >= width) {
            return -1;
        }

        // eat food?        
        if(foodIdx < food.size() && food[foodIdx] == pos) {
            score++;
            foodIdx++;
        } else {
            vector<int> pre = snakeQ.front();
            snakeS.erase(pre);
            snakeQ.pop();
        }

        if(snakeS.find(pos) != snakeS.end()) return -1;
        
        // extend the snake
        snakeS.insert(pos);
        snakeQ.push(pos);

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
