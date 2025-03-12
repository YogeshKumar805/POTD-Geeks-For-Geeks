class Solution:
    def minCostClimbingStairs(self, cost):
        #Write your code here
        if len(cost) < 2:
            return 0
        sec_last, last = cost[:2]
        for idx in range(2, len(cost)):
            curr_cost = cost[idx] + min(sec_last, last)
            sec_last = last
            last = curr_cost
        
        return min(last, sec_last)
