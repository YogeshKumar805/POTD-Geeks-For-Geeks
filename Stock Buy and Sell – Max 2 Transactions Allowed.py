class Solution:
    def maxProfit(self, prices):
        # code here
        if not prices:
            return 0
            
        fb = float('inf')
        fp = 0
        sb = float('inf')
        sp = 0
            
            
        for i in prices:
            fb = min(fb, i)
            fp = max(fp, i - fb)
            
            sb = min(sb, i - fp)
            sp = max(sp, i - sb)
                
                
        return sp
