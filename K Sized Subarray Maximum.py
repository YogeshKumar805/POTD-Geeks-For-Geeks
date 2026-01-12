from collections import deque
class Solution:
    def maxOfSubarrays(self, arr, k):
        
        dq = deque()
        res = []
        
        for i, v in enumerate(arr):
            
            # drop items out of current window
            while dq and dq[0] <= i - k:
                dq.popleft()
            
            # drop items which violate constraint
            # monotonic decreasing deque
            while dq and arr[dq[-1]] < v:
                dq.pop()
                
            dq.append(i)
            
            if i >= k - 1:
                res.append(arr[dq[0]])
        
        return res
