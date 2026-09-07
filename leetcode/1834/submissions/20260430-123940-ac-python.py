# 1834. Single-Threaded CPU
# Difficulty: Medium
# Status: Accepted
# Runtime: 2991 ms (beats 5.1%)
# Memory: 53.2 MB (beats 71.9%)
# Submitted: 2026-04-30 12:39:40 UTC
# URL: https://leetcode.com/submissions/detail/1991810266/

"""
- sort the tasks by start time
- while i < len(tasks):
    - gather the tasks that are "available" at current timestamp
    - pick one with least processing time
"""

class Solution(object):
    def getOrder(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: List[int]
        """
        jobs = [(enqueue_time, processing_time, i) for (i, (enqueue_time, processing_time)) in enumerate(tasks)]
        jobs.sort()
        available = []
        result = []

        print(jobs)

        t, i = jobs[0][0], 0
        while len(result) < len(jobs):
            while i < len(jobs) and jobs[i][0] <= t:
                heapq.heappush(available, (jobs[i][1], jobs[i][2]))
                i += 1

            if available:
                processing_time, job_id = heapq.heappop(available)
                result.append(job_id)
                t += processing_time
            else:
                t = jobs[i][0]
        
        return result

        
