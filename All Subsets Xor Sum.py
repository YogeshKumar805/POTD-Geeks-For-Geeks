class Solution:
    def subsetXORSum(self, arr):
        res = 0
        n = -1
        for i in arr:
            res|=i
            n+=1
        return 2**n*res
