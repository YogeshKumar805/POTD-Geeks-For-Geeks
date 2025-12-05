class Solution:
    def minCost(self, costs):
        n = len(costs)
        if n == 0:
            return 0

        k = len(costs[0])
        if k == 0:
            return -1

        if k == 1:
            return costs[0][0] if n == 1 else -1

        dp = costs[0][:]

        for i in range(1, n):
            new_dp = [0] * k

            min1 = min2 = float('inf')
            idx1 = -1

            for j in range(k):
                if dp[j] < min1:
                    min2 = min1
                    min1 = dp[j]
                    idx1 = j
                elif dp[j] < min2:
                    min2 = dp[j]

            for j in range(k):
                if j == idx1:
                    new_dp[j] = costs[i][j] + min2
                else:
                    new_dp[j] = costs[i][j] + min1

            dp = new_dp

        return min(dp)class Solution:
    def minCost(self, costs):
        n = len(costs)
        if n == 0:
            return 0

        k = len(costs[0])
        if k == 0:
            return -1

        if k == 1:
            return costs[0][0] if n == 1 else -1

        dp = costs[0][:]

        for i in range(1, n):
            new_dp = [0] * k

            min1 = min2 = float('inf')
            idx1 = -1

            for j in range(k):
                if dp[j] < min1:
                    min2 = min1
                    min1 = dp[j]
                    idx1 = j
                elif dp[j] < min2:
                    min2 = dp[j]

            for j in range(k):
                if j == idx1:
                    new_dp[j] = costs[i][j] + min2
                else:
                    new_dp[j] = costs[i][j] + min1

            dp = new_dp

        return min(dp)
