/*
 * 981. Time Based Key-Value Store
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 785 ms (beats 5.4%)
 * Memory: 99.3 MB (beats 81.3%)
 * Submitted: 2022-08-25 14:22:09 UTC
 * URL: https://leetcode.com/submissions/detail/783116050/
 */


var TimeMap = function() {
    this.map = new Map();
};

/** 
 * @param {string} key 
 * @param {string} value 
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function(key, value, timestamp) {
    if(!this.map.has(key)){
        this.map.set(key, []);
    }
    
    this.map.get(key).push([value, timestamp]);
};

/** 
 * @param {string} key 
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function(key, timestamp) {
    let res = ""; 
    if (!this.map.has(key)) return ""; 
    let values = this.map.get(key);
    
    let m = 0, l = 0, r = values.length - 1;
    while (l <= r){
        m = Math.floor((l + r) / 2);
        if (values[m][1] <= timestamp){
            res = values[m][0];
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    
    return res;
};

/** 
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */
