class Solution:
    def smallestDiff(self,a, b, c):
        a.sort()
        b.sort()
        c.sort()
        lth=len(a)
        aa=bb=cc=0
        mn=float('inf')
        sel=[]
        while aa<lth and bb<lth and cc<lth:
            cand=[a[aa],b[bb],c[cc]]
            if mn>max(cand)-min(cand):
                mn=max(cand)-min(cand)
                sel=cand[:]
            if a[aa]<=b[bb] and a[aa]<=c[cc]:
                aa+=1
            elif a[aa]>=b[bb] and b[bb]<=c[cc]:
                bb+=1
            else:
                cc+=1
        return sorted(sel,reverse=True)
