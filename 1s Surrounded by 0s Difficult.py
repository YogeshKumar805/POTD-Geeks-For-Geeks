class Solution:
    def cntOnes(self, grid):
        n, m = len(grid), len(grid[0])

        directions = [(0,1), (0,-1), (1,0), (-1,0)]

        def dfs(i, j):
            grid[i][j] = 2

            for dx, dy in directions:
                ni, nj = i + dx, j + dy

                if 0 <= ni < n and 0 <= nj < m and grid[ni][nj] == 1:
                    dfs(ni, nj)
        for i in range(n):
            if grid[i][0] == 1:
                dfs(i, 0)

            if grid[i][m - 1] == 1:
                dfs(i, m - 1)

        for j in range(m):
            if grid[0][j] == 1:
                dfs(0, j)

            if grid[n - 1][j] == 1:
                dfs(n - 1, j)
        ans = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans += 1

        return ans
