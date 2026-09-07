/*
 * 3508. Implement Router
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 521 ms (beats 5.0%)
 * Memory: 445.2 MB (beats 33.8%)
 * Submitted: 2026-07-25 11:23:04 UTC
 * URL: https://leetcode.com/submissions/detail/2080663506/
 */

class Router {
    int memoryLimit;
    deque<string> dq;
    unordered_set<string> keys;
    unordered_map<int, deque<int>> timeStampByDest;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {};

    bool addPacket(int source, int destination, int timestamp) {
        string key = serialize(source, destination, timestamp);
        
        if(keys.count(key)) return false;
        if(keys.size() == memoryLimit) this->forwardPacket();
        
        dq.push_back(key);
        keys.insert(key);
        timeStampByDest[destination].push_back(timestamp);
        
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        
        string key = dq.front();
        vector<int> res = deserialize(key);
        int destination = res[1], timestamp = res[2];

        dq.pop_front();
        keys.erase(key);
        timeStampByDest[destination].pop_front();

        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& destDq = timeStampByDest[destination];
        auto lo = lower_bound(destDq.begin(), destDq.end(), startTime);
        auto hi = upper_bound(destDq.begin(), destDq.end(), endTime);
        return hi - lo;
    }

    string serialize(int source, int destination, int timestamp) {
        return format("{}:{}:{}", source, destination, timestamp);
    }

    vector<int> deserialize(string& key) {
        vector<int> result;
        stringstream ss(key);
        string token;
        while(getline(ss, token, ':')) {
            result.push_back(stoi(token));
        }
        return result;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
