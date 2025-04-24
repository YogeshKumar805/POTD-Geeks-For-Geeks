from collections import Counter
class Solution:
    def getSingle(self, arr):
        # code here 
        c = Counter(arr)
        
        for i in c.keys():
            if c[i] == 1:
                return i
