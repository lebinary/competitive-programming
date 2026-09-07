# 621. Task Scheduler
# Difficulty: Medium
# Status: Accepted
# Runtime: 475 ms (beats 5.5%)
# Memory: 17 MB (beats 100.0%)
# Submitted: 2024-09-24 16:32:42 UTC
# URL: https://leetcode.com/submissions/detail/1400923903/

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # increment the time:
        #   pop most frequent count task
        #   schedule same task with decreased count
        #   
        #   if q:
        #       pop scheduled task and push into heap

        counter = Counter(tasks)
        max_heap = [-c for c in counter.values()]
        heapq.heapify(max_heap)
        q = deque()

        time = 0
        while max_heap or q:
            time += 1

            if max_heap:
                count = heapq.heappop(max_heap)
                next_count = count + 1

                if next_count != 0: 
                    q.append((next_count, time + n))

            if q and q[0][1] == time:
                scheduled_count, _ = q.popleft()
                heapq.heappush(max_heap, scheduled_count)
        
        return time
