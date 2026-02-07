class Solution:
    def maxSum(self, arr): 
        # Code here
        pro=0
        su=0
        n=len(arr)
        ans=0
        for i in range(n):
            pro+=i*arr[i]
            su+=arr[i]
        for i in range(n):
            pro-=su-n*arr[i]
            if pro>ans:
                ans=pro
        return ans
