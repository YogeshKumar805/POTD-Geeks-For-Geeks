class Solution:
    def check(self, s1, s2, idx):
        for i in range(len(s1)):
            if(s1[i] != s2[idx]):
                return False, i
            idx = (idx+1)%len(s1)
        return True, -1
    def areRotations(self, s1, s2):
        i = 0
        while(i<len(s1)):
            if s2[i] == s1[0]:
                is_valid, idx = self.check(s1, s2, i)
                if(is_valid):return True
                if i < idx:i = idx-1
            i+=1
            
        return False
