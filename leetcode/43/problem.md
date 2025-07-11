## 43. Multiplying String

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

**Example 1:**
Input: num1 = "2", num2 = "3"
Output: "6"

**Example 2:**
Input: num1 = "123", num2 = "456"
Output: "56088"

**Constraints:**
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

**Thoughts**
- Small constraint => O(n^2) algorithm should be good enough
- Pseudo:
  - For each `i` in num1, `j` in `num2`, in reverse:
    - Calcualte prod = num1[i] * num2[j], digit = prod % 10, carry = prod / 10
    - Update res[i + j] += digit
    - Update res[i + j - 1] += carry
  - Return res, remove any leading zeros
