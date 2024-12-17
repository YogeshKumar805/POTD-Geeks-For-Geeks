class Solution:
    def aggressiveCows(self, stalls, k):
        stalls.sort()
        def ok(mid):
            nonlocal stalls,k
            prv=-float('inf')
            cnt=0
            for ve in stalls:
                if ve-prv>=mid:
                    prv=ve
                    cnt+=1
                    if cnt==k:
                        return True
            return False
        left=1
        right=stalls[-1]-stalls[0]
        while left<right:
            mid=left+(right-left)//2
            if ok(mid):
                left=mid+1
            else:
                right=mid
        return left-1

