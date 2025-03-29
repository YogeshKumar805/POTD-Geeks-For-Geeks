class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        from heapq import heappush, heappop
        jobs = list(zip(deadline, profit))
        jobs.sort()
        max_profit = 0
        job_count = 0
        max_heap = []
        index = len(jobs) - 1
        
        for i in range(jobs[-1][0], 0, -1):
            while index >= 0 and jobs[index][0] == i:
                heappush(max_heap, -jobs[index][1]) 
                index -= 1
            
            if max_heap:
                job_count += 1
                max_profit += -heappop(max_heap)
        
        return [job_count, max_profit]
 
