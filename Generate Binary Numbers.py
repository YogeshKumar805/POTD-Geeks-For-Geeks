class Solution:
    def generateBinary(self, n):
        from collections import deque
        q = deque()
        q.append("1")
        res = []
        for i in range(n//2):
            val = q.popleft()
            res.append(val)
            q.append(val+"0")
            q.append(val+"1")
        res = res + list(q)
        return res[0:n]
