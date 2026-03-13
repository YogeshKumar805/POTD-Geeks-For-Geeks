class Solution:
    def generateIp(self, s):
        n = len(s)
        res = []
        def valid(s):
            if len(s) >= 2 and s[0] == '0':
                return False
            return 0 <= int(s) <= 255
        
        def f(idx, parts, curr):
            if idx == n and parts == 4:
                temp = list(curr)[:-1]
                res.append("".join(temp))
                return
            
            if parts >= 4:
                return
            
            i = 1
            while i <= 3 and idx+i <= n:
                temp = s[idx:idx+i]
                if valid(temp):
                    f(idx+i, parts+1, curr + temp + '.')
                i += 1
        
        f(0, 0, "")
        return res

