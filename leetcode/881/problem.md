## 881. Boats to Save People

You are given an integer array people where `people[i]` is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of `limit`. Each boat carries `at most two people` at the same time, provided the sum of the weight of those people is at most limit.

Return the `minimum number of boats` to carry every given person.

**Example 1:**
Input: people = [5,1,4,2], limit = 6
Output: 2
Explanation:
First boat [5,1].
Second boat [4,2].

**Example 2:**
Input: people = [1,3,2,3,2], limit = 3
Output: 4
Explanation:
First boat [3].
Second boat [3].
Third boat [1,2].
Fourth boat [2].

**Constraints:**
1 <= people.length <= 50,000
1 <= people[i] <= limit <= 30,000

**Thoughts**
- Threshold = sum(people) / limit
  i.e
  sum([5,1,4,2]) / 6 = 2
  sum([1,3,2,3,2]) / 3 = 3.6
- One boat can have at least 1 person (because people[i] <= limit for all i) and at most 2 persons.
- Can I sort then slide window this?
  sort(people)
  slide window:
    if people[l] + people[r] <= limit:
      l++
      r--
    else:
      r--
