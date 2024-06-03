class Solution:
    def numberOfConsecutiveOnes (ob,n):
        # code here 
        that, this = 0, 1
        
        for p in range(1, n-1):
            that, this = this, (that + this + pow(2, p, (10**9 + 7)))%(10**9 + 7)
            
        return this
