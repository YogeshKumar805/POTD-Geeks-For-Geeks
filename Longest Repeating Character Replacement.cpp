class Solution:
    def longestSubstr(self, s, k):
        def ok(cnt):
            nonlocal k
            sm=sum(cnt.values())
            mx=max(cnt.values())
            return sm-mx<=k
        cnt={}
        l=0
        mx=0
        for r,c in enumerate(s):
            cnt[c]=cnt.get(c,0)+1
            while not ok(cnt):
                cnt[s[l]]-=1
                l+=1
            mx=max(mx,r-l+1)
        return mx
