/*
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 112 ms (beats 5.3%)
 * Memory: 52.5 MB (beats 100.0%)
 * Submitted: 2021-11-04 04:39:20 UTC
 * URL: https://leetcode.com/submissions/detail/581836776/
 */

/**
 * @param {number[]} nums
 * @return {number[]}
 */
// var productExceptSelf = function(nums) {
//     const n = nums.length;
   
//     /***
//         Create a prefix array
//         from [1 , 2 , 3, 4] 
//         to   [1,  2,  6, 24]
//     ***/
//     let prefix = Array(n).fill(1);
//     prefix[0] = nums[0];
//     for(let i = 1; i < n; i++){
//         prefix[i] = nums[i] * prefix[i-1];
//     }
//     console.log('prefix: ', prefix);
    
    
//     /***
//         Create a postfix array
//         from [1 , 2 , 3 , 4] 
//         to   [24, 24, 12, 4]
//     ***/
//     let posfix = Array(n).fill(1);
//     posfix[n-1] = nums[n-1];
//     for(let i = n-2; i >= 0; i--){
//         posfix[i] = nums[i] * posfix[i+1];
//     }
//     console.log('postfix: ', posfix);
    
//     const answers = [];
//     answers.push(posfix[1]);
//     for(let i = 1; i < n-1; i++){
//         answers.push(prefix[i-1] * posfix[i+1]);
//     }
//     answers.push(prefix[n-2]);
//     return answers;
// };


/***
    Shorter version: store in "answers" array
    without using "prefix" and "posfix" arrays
***/
var productExceptSelf = function(nums) {
    const n = nums.length;
    const answers = Array(n).fill(1);
    
    //Add prefix
    for(let i = 1; i < n; i++){
        answers[i] = nums[i-1] * answers[i-1];
    }
    console.log(answers);
    
    //Multiply to posfix
    let post = 1;
    for(let i = n-2; i >= 0; i--){
        post *= nums[i+1];
        answers[i] *= post
    }
    
    return answers;
};
