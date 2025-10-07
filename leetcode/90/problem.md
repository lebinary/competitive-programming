## Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

**Example 1:**
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

**Example 2:**
Input: nums = [0]
Output: [[],[0]]

**Constraints:**
1 <= nums.length <= 10
-10 <= nums[i] <= 10

**Thoughts:**
- At any point, there are 2 decisions: add or no add
- []  -> [1]  -> [1, 2] -> [1, 2, 2]
                        -> [1, 2]
              -> [1]    -> [1, 2] (duplicated)
                        -> [1]
      -> []   -> [2]    -> [2, 2]
                        -> [2]
              -> []     -> [2] (duplicated)
                        -> []
- How to deal with duplicate? sort and only enter path if nums[i] != nums[i_next]
