#User function Template for python3
class Solution:
    def recurse(self, n, l, num, countZ, countO):
        if n == 0:
            if countO >= countZ:
                l.append(num)
            return 
        if countO >= countZ:
            self.recurse(n-1, l, num*10+1, countZ, countO+1)
            self.recurse(n-1, l, num*10+0, countZ+1, countO)
        return l
    def NBitBinary(self, n):
        # code here
        if n == 1:
            return "1"
        l = []
        countZ = 0
        countO = 1
        l = self.recurse(n-1, l, 1, countZ, countO)
        return l
