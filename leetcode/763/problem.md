## 763. Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

**Example 1:**
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

**Example 2:**
Input: s = "eccbbbbdec"
Output: [10]

**Constraints:**
1 <= s.length <= 500
s consists of lowercase English letters.

**Thoughts:**
- Given a postion, it is "splitable" if it doesn't cut through any 1 character's horizontal line
  For example: `ababcc`. The number of horizontal lines we can have is
  - `a`: [0, 2]
  - `b`: [1, 3]
  - `c`: [4, 5]
- Actually, can we convert this to 1D? create a 1D array with only 0/1 values, where 1 means "occupied", 0 means "available" => Yes
- Algorithm:
  - Go through the string, create a map {[char]: [left_idx, right_idx]};
  - Merge phase, go through each horizontal and trying to merge them, condition for merge is the one horizontal's end is another horiontal's start. So:
    - `a.b`: [0, 3]
    - `c`: [4, 5]
    => final partitions
  - Return the size of each part, so [4, 2]
