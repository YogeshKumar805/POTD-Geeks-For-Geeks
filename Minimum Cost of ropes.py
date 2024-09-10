import heapq

class Solution:
    #Function to return the minimum cost of connecting the ropes.
    def minCost(self,arr) :
            
        heapq.heapify(arr)
        ans=0
        while len(arr)>1:
            
            a = heapq.heappop(arr)
            b = heapq.heappop(arr)
            
            c = a+b
            
            ans+=c
            
            heapq.heappush(arr,c)

        return ans
