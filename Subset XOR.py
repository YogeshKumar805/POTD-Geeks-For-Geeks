class Solution:
    def subsetXOR(self, n : int):
        # code here
        x=0
        for i in range(1,n+1):
            x^=i
        if x==n:
            return [i for i in range(1,n+1)]
        missing=x^n
        if missing>0 and missing<n:
            return [i for i in range(1,n+1) if i!=missing]
        if missing==n:
           return [i for i in range(1,n)] 
