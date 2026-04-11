class Solution:
    def countIncreasing(self, arr):
        n = len(arr)
        length = 1
        ans = 0
        for i in range(1,n):
            if arr[i]>arr[i-1]:
                length+=1
                ans += (length-1)
            else:
                length = 1
        return ans
