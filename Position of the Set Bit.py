class Solution:
    def findPosition(self, n):
        # code here 
        s = bin(n)
        c = 0
        if n == 0:
            return -1
        pos = 0
        ans = -1
        for i in s[::-1]:
            pos += 1
            if i == '1':
                c += 1
                ans = pos
        if c == 1:
            return ans
        return -1
