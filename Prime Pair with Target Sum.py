class Solution:
    def getPrimes(self, n : int) -> List[int]:
        # code here
        prime = [True for i in range(n+1)]
        prime[0] = prime[1] = False
        p = 2
        while (p * p <= n):
            if (prime[p] == True):
                for i in range(p * p, n+1, p):
                    prime[i] = False
            p += 1
        for i in range(n):
            if prime[i] and prime[n-i]:
                return [i,n-i]
        return [-1,-1]
