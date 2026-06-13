class Solution:
    def computeValue(self, n):
        MOD = 10**9 + 7

        fact = [1] * (2 * n + 1)
        for i in range(1, 2 * n + 1):
            fact[i] = (fact[i - 1] * i) % MOD

        inv_fact_n = pow(fact[n], MOD - 2, MOD)

        return (fact[2 * n] * inv_fact_n % MOD * inv_fact_n) % MOD
