class Solution:
    def sameOccurrence(self, arr, x, y):
        d = {}
        pre = 0
        res= 0
        for i in range(len(arr)):
            if arr[i]==x:
                pre+=x 
            if arr[i]==y:
                pre+= -x 
            if pre==0:
                res+=1
                
            if pre in d:
                res+= d[pre]
            d[pre] = d.get(pre,0)+1
        return res
