class Solution:
    def maxSubarrayXOR(self, arr, k):
        # code here
        xor=0
        ans=0
        for i in range(k-1):
            xor=xor^arr[i]
        for i in range(k-1,len(arr)):
            xor=xor^arr[i]
            if xor>ans:
                ans=xor
            xor=xor^arr[i-k+1]
        return ans
