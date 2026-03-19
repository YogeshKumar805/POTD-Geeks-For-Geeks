class Solution:
    def largestBst(self, root):
        ret=1
        def dfs(cur=root):
            nonlocal ret
            if not cur:
                return 0,float('inf'),-float('inf'),True
            la,lb,lc,ld=dfs(cur.left)
            ra,rb,rc,rd=dfs(cur.right)
            if ld and rd and lc<cur.data<rb:
                ca=1+la+ra
                ret=max(ret,ca)
                cb=min(lb,cur.data)
                cc=max(rc,cur.data)
                return ca,cb,cc,True
            return 0,None,None,False
        dfs()
        return ret
