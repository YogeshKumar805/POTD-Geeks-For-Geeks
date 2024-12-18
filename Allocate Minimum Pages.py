class Solution:
    
    #Function to find minimum number of pages.
    def findPages(self, arr, k):
        if k>len(arr):
            return -1
        def fun(arr,mid):
            students=1
            countpages=0
            for i in range(len(arr)):
                if countpages+arr[i]<=mid:
                    countpages+=arr[i]
                else:
                    students+=1
                    countpages=arr[i]
            return students
        low=max(arr)
        high=sum(arr)
        res=-1
        while low<=high:
            mid=(low+high)//2
            count=fun(arr,mid)
            if count>k:
                low=mid+1
            else:
                res=mid
                high=mid-1
        return res
