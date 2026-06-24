class Solution:
    def shortestDist(self, mat):
        n = len(mat)

        if mat[0][0] == 0:
            return [[-1]]

        ans = [[0] * n for _ in range(n)]
        dp = [[-1] * n for _ in range(n)]   # -1 = unknown, 0 = no path, 1 = path exists

        def dfs(i, j):
            if i >= n or j >= n or mat[i][j] == 0:
                return False

            if i == n - 1 and j == n - 1:
                ans[i][j] = 1
                return True

            if dp[i][j] == 0:
                return False

            ans[i][j] = 1

            # Try smaller jumps first
            for step in range(1, mat[i][j] + 1):

                # Right first
                if j + step < n and ans[i][j + step] == 0:
                    if dfs(i, j + step):
                        dp[i][j] = 1
                        return True

                # Down next
                if i + step < n and ans[i + step][j] == 0:
                    if dfs(i + step, j):
                        dp[i][j] = 1
                        return True

            ans[i][j] = 0
            dp[i][j] = 0
            return False

        if dfs(0, 0):
            return ans
        return [[-1]]

