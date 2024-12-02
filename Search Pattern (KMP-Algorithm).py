class Solution:
    def search(self, pat, txt):
        # code here
        a = []
        p = len(pat)
        t = len(txt)
        for i in range(t-p+1):
            s = txt[i:i+p]
            if s == pat:
                a.append(i)
        return a
