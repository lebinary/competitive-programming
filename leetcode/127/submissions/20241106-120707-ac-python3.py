# 127. Word Ladder
# Difficulty: Hard
# Status: Accepted
# Runtime: 7959 ms (beats 5.0%)
# Memory: 18.6 MB (beats 100.0%)
# Submitted: 2024-11-06 12:07:07 UTC
# URL: https://leetcode.com/submissions/detail/1444751596/

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # Approach: append "beginWord" to the start of wordList and turn this into
        # "Finding the shortest path from 1 node to another node"
        if endWord not in wordList:
            return 0

        # insert beginWord to the beginning of wordList
        wordList.insert(0, beginWord)
        n = len(wordList)
        m = len(wordList[0])

        def countDiff(s1, s2):
            return sum(1 for c1, c2 in zip(s1, s2) if c1 != c2)

        # create mapping graph
        mapping = {i:[] for i in range(n)}
        for i in range(n):
            for j in range(i + 1, n):
                # count number of difference chars
                cnt = 0
                for k in range(m):
                    if wordList[i][k] != wordList[j][k]:
                        cnt += 1
                if cnt == 1:
                    mapping[i].append(j)
                    mapping[j].append(i)

        # bfs to find the shortest path
        level = 0
        visited = set()
        target = wordList.index(endWord)

        q = deque()
        q.append(0)
        while q:
            level += 1
            for _ in range(len(q)):
                curr = q.popleft()

                if curr == target:
                    return level

                visited.add(curr)
                for nxt in mapping[curr]:
                    if nxt not in visited:
                        q.append(nxt)

        return 0
