class Solution:
    def countSubstr (self, s, k):
        return self.atMostK(s , k) - self.atMostK(s , k-1)
    def atMostK(self , s , k):
        if k == 0:
            return 0
            
        d = {}
        length = len(s)
        i = 0
        j = 0
        ans = 0
        
        while j < length:
            if s[j] in d:
                d[s[j]] += 1
            else:
                d[s[j]] = 1
            
            while i < j and len(d) > k:
                d[s[i]] -= 1
                if d[s[i]] == 0:
                    d.pop(s[i])
                i += 1
            
            ans += j-i+1
            
            j += 1
        
        return ans
