class Solution:
    def binstr(self, n):
        
        return [bin(i)[2:].zfill(n) for i in range(2**n)]
