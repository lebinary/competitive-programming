# 621. Task Scheduler
# Difficulty: Medium
# Status: Accepted
# Runtime: 471 ms (beats 5.5%)
# Memory: 17.1 MB (beats 100.0%)
# Submitted: 2024-09-15 13:50:31 UTC
# URL: https://leetcode.com/submissions/detail/1391064032/

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # keep track if count of each tasks

        # whenver we process a task;
        #   decrease the count
        #   schedule it to run in the future

        # return the time once all the tasks are done

        # Note: 
        # 1. order to process tasks is from most frequent to less frequent, therefore MaxHeap is used
        # 2. use Queue to schedule task for the furture

        counts = Counter(tasks)
        maxHeap = [-c for c in counts.values()]
        heapq.heapify(maxHeap)

        q = deque() # stores [-count, schedule_time]
        
        time = 0
        while maxHeap or q:
            time += 1
            
            # process most frequent task
            if maxHeap:
                count = heapq.heappop(maxHeap) # count of most frequent task
                next_count = count + 1 # plus one becuase we store negatives count

                # schedule the task again for the future
                if next_count != 0: # still need to process this task in the future
                    q.append((next_count, time + n))
            
            # if heap is empty, check queue if there are scheduled task
            if q and q[0][1] == time:
                scheduled_task_count = q.popleft()[0] # count of scheduled task
                heapq.heappush(maxHeap, scheduled_task_count)
        
        return time
