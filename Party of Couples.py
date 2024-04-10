class Solution:
    def findSingle(self, n, arr):
        # code here
        unique=0
        for i in arr:
            unique^=i
        return unique
