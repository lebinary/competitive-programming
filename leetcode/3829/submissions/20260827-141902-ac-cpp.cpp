/*
 * 3829. Design Ride Sharing System
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 34 ms (beats 87.1%)
 * Memory: 142.7 MB (beats 88.5%)
 * Submitted: 2026-08-27 14:19:03 UTC
 * URL: https://leetcode.com/submissions/detail/2121981210/
 */

class RideSharingSystem {
    array<bool, 1001> avaiRider;
    queue<int> riders, drivers;

public:
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        riders.push(riderId);
        avaiRider[riderId] = true;
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(drivers.empty()) return {-1, -1};

        while(!riders.empty() && !avaiRider[riders.front()]) riders.pop();
        if(riders.empty()) return {-1, -1};

        vector<int> res = {drivers.front(), riders.front()};
        drivers.pop(); riders.pop();

        return res;     
    }
    
    void cancelRider(int riderId) {
        avaiRider[riderId] = false;       
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
