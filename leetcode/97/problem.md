## Interleaving String

You are given three strings s1, s2, and s3. Return true if s3 is formed by interleaving s1 and s2 together or false otherwise.

Interleaving two strings s and t is done by dividing s and t into n and m substrings respectively, where the following conditions are met

|n - m| <= 1, i.e. the difference between the number of substrings of s and t is at most 1.
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
Interleaving s and t is s1 + t1 + s2 + t2 + ... or t1 + s1 + t2 + s2 + ...
You may assume that s1, s2 and s3 consist of lowercase English letters.

**Example 1:**
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

**Example 2:**
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

**Example 3:**
Input: s1 = "", s2 = "", s3 = ""
Output: true

**Constraints:**
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

**Thoughts:**
- Small constraint -> can try to bruteforce this
- Backtracking solution:
  - Let `i`, `j`, `k` represents index in `s1`, `s2`, `s3` respectively
  - For each `k`, we can EITHER:
    - Choose s1, if s1[i] == s3[k], increment `i`
    - Chosse s2, if s2[j] == s3[k], increment `j`
    - Return false, since no valid path forward.
  - Stop condition:
    - If `k` >= s3.size() && `i` + `j` == `k`: return `true`.
    - If `k` >= s3.size(): return `false`
