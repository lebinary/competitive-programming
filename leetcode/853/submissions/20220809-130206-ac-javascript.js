/*
 * 853. Car Fleet
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 396 ms (beats 5.0%)
 * Memory: 72 MB (beats 98.4%)
 * Submitted: 2022-08-09 13:02:06 UTC
 * URL: https://leetcode.com/submissions/detail/769323711/
 */

/**
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function(target, position, speed) {
    
    // Merged 2 arrays and sorted
    const pos_speed = [];
    
    for(let i = 0; i < position.length; i++){
        pos_speed.push([position[i], speed[i]]);
    }
                       
    pos_speed.sort((a, b) => {
      return b[0] - a[0];
    });
    
    // Actual problem solving
    const stack = [];
    
    for(let i = 0; i < pos_speed.length; i++){
        const curr_pos = pos_speed[i][0];
        const curr_speed = pos_speed[i][1];
        
        
        // Calculate time to reach destination
        const curr_time = (target - curr_pos) / curr_speed;
        stack.push(curr_time);
        
        // Check if this car will merge with previous fleet in the stack
        if(stack.length >= 2 && curr_time <= stack[stack.length-2]){
            stack.pop();
        }
        
        
    }
    
    return stack.length;
};
