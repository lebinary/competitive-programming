# 176. Second Highest Salary
# Difficulty: Medium
# Status: Accepted
# Runtime: 248 ms (beats 98.5%)
# Memory: 0B (beats 100.0%)
# Submitted: 2026-03-30 12:59:48 UTC
# URL: https://leetcode.com/submissions/detail/1963828357/

# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary
FROM employee
WHERE salary < (
    SELECT MAX(salary)
    FROM employee
);
