class Solution:
    def mergeArrays(self, a, b):
        # code here
        n1 = len(a)
        n2 = len(b)
        
        i = 0
        k = n1 -1
        j = 0
        
        while i <= k and j < n2:
            
            if a[i] <= b[j]:
                i+=1
            elif a[k] > b[j]:
                a[k], b[j] = b[j], a[k]
                j+=1
                k-=1
        a.sort()
        b.sort()
