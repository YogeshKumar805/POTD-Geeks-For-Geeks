class Solution:
    def romanToDecimal(self, s): 
        key = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        
        i = 0
        res = 0
        while i<len(s):
            if i == len(s)-1 or key[s[i]] >= key[s[i+1]]:
                res+=key[s[i]]
            else:
                res-=key[s[i]]
            i+=1
        return res
        
