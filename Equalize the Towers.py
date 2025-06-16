class Solution:
    def minCost(self, heights, cost):
        def calc(m):
            res=0
            for i,h in enumerate(heights):
                res+=abs(h-m)*cost[i]
            return res
            
        low=min(heights)
        high=max(heights)
        res=float('inf')
        while(low<=high):
            mid=(low+high)//2
            c1=calc(mid-1)
            c2=calc(mid)
            c3=calc(mid+1)
            if c1>=c2<=c3:
                res=c2
                break
            elif(c1>=c2>=c3):
                low=mid+1
            else:
                high=mid-1
        return res

#Ternarysearch
class Solution:
    def minCost(self, heights, cost):
        def calc(m):
            return sum(abs(h - m) * c for h, c in zip(heights, cost))
        low, high = min(heights), max(heights)
        while high - low > 2:
            t = (high - low) // 3
            mid1 = low + t
            mid2 = high - t
            c1 = calc(mid1)
            c2 = calc(mid2)
            if c1 < c2:
                high = mid2
            else:
                low = mid1
        return min(calc(h) for h in range(low, high + 1))
 
