## 879. Profitable Schemes

There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

Example 1:
Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.

Example 2:
Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

**Thought process:**
- Similar to "Zeroes and Ones" problem, but instead of having 2 upper bounds `m` - number of zeros, and `n` - number of ones, we have 1 upper bound and 1 lower bound (`n` , `minProfit`). Nevertheless, those are still just thresholds to work with.
- setup 3D dp matrix, where dp[k][i][j] represents the number of schemes that can be chosen up until `k` crimes, with at most `i` members, and at least `j` profit.
