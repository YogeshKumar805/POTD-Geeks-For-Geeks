class Solution:
    def cntWays(self, arr):
        # cur_odde here
        ans=0
        ev=0
        od=0
        te=True
        for i in arr:
            if te:
                ev+=i
            else:
                od+=i
            te=not te
        #print(ev,od)
        cur_even=0
        cur_odd=0
        te=True
        for i in arr:
            if te:
                ev-=i
                if cur_even+od==cur_odd+ev:
                    ans+=1
                cur_even+=i
            else:
                od-=i
                if cur_even+od==cur_odd+ev:
                    ans+=1
                cur_odd+=i
            te=not te
        return ans
