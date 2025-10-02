class Solution:
    def combinationSum(self, n, k):
        cur=[]
        ret=[]
        def bt(cand=9):
            nonlocal n,k,cur,ret
            if k==0:
                if n==0:
                    ret.append(cur[:])
                return
            if cand<=0 or n<=0:
                return
            cur.append(cand)
            k-=1
            n-=cand
            bt(cand-1)
            cur.pop()
            k+=1
            n+=cand
            bt(cand-1)
        bt()
        return ret

