class Solution:
    def isAdditiveSequence(self, n):
        #code here
        def vs(a,s,r):
            if not r:
                return True
            sn = str(a+s)
            if r.startswith(sn):
                return vs(s,int(sn),r[len(sn):])
            return False
        l = len(n)
        for i in range(1,l):
            for j in range(i+1,l):
                a = int(n[:i])
                s = int(n[i:j])
                if vs(a,s,n[j:]):
                    return 1
        return 0
