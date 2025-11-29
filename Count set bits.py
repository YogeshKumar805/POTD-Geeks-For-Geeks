import math
class Solution:
    #Function to return sum of count of set bits in the integers from 1 to n.
    def countSetBits(self,n):
        # code here
        # return the count
        s=0
        while n>0:
            x=int(math.log2(n))
            if x==0:
                s+=1
                break
            s+=x*(1<<(x-1))+(n-(1<<x)+1)
            n-=(1<<x)
        return s
