class Solution:
    def minCost(self, heights, costs):
        def ok(mid):
            totalCost = 0
            for _, (height, cost) in enumerate(zip(heights, costs)):
                totalCost += abs(height-mid)*cost
            return totalCost
        
        l, h = min(heights), max(heights)        
        while l <= h:
            mid = l+(h-l)//2
            
            prev = ok(mid-1)
            curr = ok(mid)
            nxt = ok(mid+1)
            
            if prev >= curr and curr <= nxt:
                return curr
                
            if prev >= curr and curr >= nxt:
                l = mid+1
            else:
                h = mid-1
        return -1
