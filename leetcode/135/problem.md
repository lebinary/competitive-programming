## 135. Candy

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Solution 1: double loops
ratings = [1, 2, 2, 3, 6, 4]
candies = [1, 2, 1, 2, 3, 1]

ratings = [3, 2, 1, 5, 4, 3]
candies = [3, 2, 1, 3, 2, 1]

ratings = [3, 2, 1, 3, 9, 9]
candies = [3, 2, 1, 2, 3, 1]

=> O(n^2)


Solution 2: 1 loop forward, then 1 loop backward, take the max.
Insight: at any given i, we only care about the neighbors (i - 1) and (i + 1)

ratings = [1, 2, 2, 3, 6, 4]
<!-- forward = [1, 2, 1, 2, 3, 1] -->
<!-- bacward = [1, 2, 1, 1, 2, 1] -->
candies = [1, 2, 1, 2, 3, 1]
