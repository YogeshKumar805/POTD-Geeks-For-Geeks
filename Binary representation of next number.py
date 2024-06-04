class Solution:
    def binaryNextNumber(self, s):
        # code here
        res = int(s,2)
        b = bin(res+1)[2:]
        return b
