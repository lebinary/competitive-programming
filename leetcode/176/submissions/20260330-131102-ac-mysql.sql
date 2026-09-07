# 176. Second Highest Salary
# Difficulty: Medium
# Status: Accepted
# Runtime: 285 ms (beats 71.3%)
# Memory: 0B (beats 100.0%)
# Submitted: 2026-03-30 13:11:02 UTC
# URL: https://leetcode.com/submissions/detail/1963837510/

# Write your MySQL query statement below
SELECT (
    SELECT salary
    FROM (
        SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
        FROM employee
    ) as ranked
    WHERE rnk = 2
    LIMIT 1
) as SecondHighestSalary
