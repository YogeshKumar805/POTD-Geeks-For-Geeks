class Solution:
    def maxWater(self, arr):
        # code here
        maxi=0
        n=len(arr)
        l=0
        r=n-1
        while l<r:
            dist=r-l
            val=min(arr[r],arr[l])
            maxi=max(maxi,val*dist)
            if arr[l]<arr[r] and l<=r:
                l+=1
            else:
                r-=1
        return maxi
