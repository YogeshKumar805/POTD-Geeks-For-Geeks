class Solution:
    def countSubarrays(self, arr, k):
        l=len(arr)
        le=0
        ri=0
        lp=-1
        rp=-1
        ans=0
        c=0
        while ri<l:
            lp=le
            rp=ri
            while ri<l:
                if arr[ri]%2==0:
                    ri+=1
                elif c<k:
                    c+=1
                    if c==k:
                        rp=ri
                    ri+=1
                else:
                    break
            while lp<ri and lp<l:
                if arr[lp]%2==0:
                    lp+=1
                else:
                    break
            #print(le,lp,rp,ri,c)
            if c==k:
                ans+=((lp-le)*(ri-rp-1))+lp-le+ri-rp
            le=lp+1
            c-=1
        return ans
