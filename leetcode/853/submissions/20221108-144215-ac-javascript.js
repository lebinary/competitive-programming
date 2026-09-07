/*
 * 853. Car Fleet
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 601 ms (beats 5.0%)
 * Memory: 80.8 MB (beats 96.4%)
 * Submitted: 2022-11-08 14:42:15 UTC
 * URL: https://leetcode.com/submissions/detail/839465261/
 */

/**
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function(target, position, speed) {
    // Merged 2 array
    const mergedArr = position.map((pos, i) => [pos, speed[i]]);

    // Sorted decending based on position
    mergedArr.sort((a, b) => b[0] - a[0]);
    console.log(mergedArr)
    const timeStack = [];
    for(let i = 0; i < mergedArr.length; i++){
        const currPos = mergedArr[i][0];
        const currSpd = mergedArr[i][1];

        // time to reach target
        const currTime = (target - currPos) / currSpd;

        // Check for number of fleets
        if(timeStack.length === 0) timeStack.push(currTime);
        else{
            // New separate fleet
            if(currTime > timeStack[timeStack.length - 1]) timeStack.push(currTime);
        }
    }

    return timeStack.length;
};
