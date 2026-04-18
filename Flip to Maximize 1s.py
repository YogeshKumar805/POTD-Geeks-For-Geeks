class Solution:
    def maxOnes(self, arr):
        mx = csum = ones = 0
        for x in arr:
            if x==0:
                csum+=1
            elif x==1:
                ones+=1
                csum-=1
            mx = max(mx, csum)
            if csum<0:
                csum = 0
        return mx+ones
