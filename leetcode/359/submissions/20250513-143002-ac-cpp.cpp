/*
 * 359. Logger Rate Limiter
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 9 ms (beats 50.3%)
 * Memory: 39.1 MB (beats 89.1%)
 * Submitted: 2025-05-13 14:30:02 UTC
 * URL: https://leetcode.com/submissions/detail/1632890762/
 */

class Logger {
    unordered_map<string, int> record;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(record.find(message) == record.end()) {
            record[message] = timestamp;
            return true;
        }
        
        int diff = timestamp - record[message];
        if(diff < 10) return false;

        record[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
