class Solution:
    def findSmallest(self, arr):
        res = 1  
        for i in arr:
            if i > res: 
                break 
            res += i 
        return res
