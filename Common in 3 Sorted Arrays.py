class Solution:
    def commonElements(self, a, b, c):
        # code here
        a = set(a)
        b = set(b)
        c = set(c)
        
        ans = []
        for val in a:
            if val in b and val in c:
               ans.append(val)
        
        return sorted(ans)
