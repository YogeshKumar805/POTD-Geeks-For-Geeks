class Solution:
    def minMaxCandy(self, prices, k):
        prices.sort()
        mini=0
        maxi=0
        i=0
        j=len(prices)-1
        l=len(prices)-1
        while i<=j:
            mini+=prices[i]
            maxi+=prices[l]
            j-=k
            i+=1
            l-=1
        return [mini,maxi]
