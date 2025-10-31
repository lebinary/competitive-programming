## 50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

**Example 1:**
Input: x = 2.00000, n = 10
Output: 1024.00000

**Example 2:**
Input: x = 2.10000, n = 3
Output: 9.26100

**Example 3:**
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

**Constraints:**
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104

**Thoughts**:
- 3 cases: n == 0, n > 0, n < 0
  - Case 1: n == 0:
    return 1
  - Case 2: n > 0:
    return x * pow(x, n - 1)
  - Case 3: n < 0:
    return 1/x * pow(x, n + 1)
- Optimization? yes, with logarithmic recursion.
  Insight: n^8 = n^4 * n^4 and n^4 = n^2 * n^2 => just calculate once, then time with itself

  Case 1: n > 0
    case 1a: n is even => return **pow(x, n / 2)^2**
    case 1b: n is odd => return **x * pow(x, n /2)^2**
  Case 2: n < 0
    case 2a: n is even => return **pow(x, n / 2)^2**
    case 2b: n is odd => return **1/x * pow(x, n/2)^2**
