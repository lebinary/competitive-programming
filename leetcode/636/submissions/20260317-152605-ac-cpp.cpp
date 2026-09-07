/*
 * 636. Exclusive Time of Functions
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 35 ms (beats 5.7%)
 * Memory: 28.5 MB (beats 5.1%)
 * Submitted: 2026-03-17 15:26:06 UTC
 * URL: https://leetcode.com/submissions/detail/1951226515/
 */

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> stack;

        vector<vector<string>> logsVec(logs.size(), vector<string>());
        for(int i = 0; i < logs.size(); ++i) {
            stringstream ss(logs[i]);
            string s;
            while(getline(ss, s, ':')) logsVec[i].push_back(s);
        }

        for(int i = 0; i < logsVec.size(); ++i) {
            vector<string>& curr = logsVec[i];
            if(stack.empty()) {
                stack.push(stoi(curr[0]));
                continue;
            }

            vector<string>& prev = logsVec[i - 1];
            if(prev[1] == "start" && curr[1] == "start") {
                res[stack.top()] += stoi(curr[2]) - stoi(prev[2]);
                stack.push(stoi(curr[0]));
            } else if(prev[1] == "start" && curr[1] == "end") {
                res[stack.top()] += stoi(curr[2]) - stoi(prev[2]) + 1;
                stack.pop();
            } else if(prev[1] == "end" && curr[1] == "start") {
                res[stack.top()] += stoi(curr[2]) - stoi(prev[2]) - 1;
                stack.push(stoi(curr[0]));
            } else {
                res[stack.top()] += stoi(curr[2]) - stoi(prev[2]);
                stack.pop();
            }
        }

        return res;
    }
};
/**
# Ideas: There are 4 cases
- start -> start: 
    res[stack.top] += start - previousLog
- start -> end: (can only be the same task, implicit)
    res[stack.top] += end - start + 1
    stack.pop
- end -> start:
    res[stack.top] += start - previousLog - 1
    stack.pop
- end -> end:
    res[stack.top] += end - previousLog

# Approach: Stack
- stack to store id
- for each log:
    if stack.emty: push & continue

    if curr.type == start && prev.type == end:
        res[stack.top] += curr.time - prev.time
        stack.push(curr.id)
    elif curr.type == end && prev.type == start:
        res[stack.top] += curr.time - prev.time + 1
        stack.pop
    elif curr.type = start && prev.type == end:
        res[stack.top] += curr.time - prev.time - 1
        stack.push(curr.id)
    else
        res[stack.top] += curr.time - prev.time
        stack.pop

**/
