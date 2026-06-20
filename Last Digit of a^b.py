class Solution:
    def helper(self, a, b):
        if b == 0:
            return 1

        if b == 1:
            return a
        
        half = self.helper(a, b // 2) ** 2 * self.helper(a, b % 2)
        return half % 10

    def getLastDigit(self, a, b):
        # code here
        a = int(a[-1])
        b = int(b)
        return self.helper(a, b)
