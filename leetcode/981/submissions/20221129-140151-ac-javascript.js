/*
 * 981. Time Based Key-Value Store
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 748 ms (beats 5.4%)
 * Memory: 100.3 MB (beats 65.0%)
 * Submitted: 2022-11-29 14:01:51 UTC
 * URL: https://leetcode.com/submissions/detail/851760150/
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
    if(!this.map.has(key)) return "";

    let arr = this.map.get(key);
    let l = 0;
    let r = arr.length - 1;

    let res = "";
    while(l <= r){
        let mid = Math.floor((l + r) / 2);

        if(arr[mid][1] <= timestamp){
            res = arr[mid][0];
            l = mid + 1;
        }else {
            r = l - 1;
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
