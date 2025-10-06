class Solution:
    def knightTour(self, n):
        MOVES = [(-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)]
        end_step = n * n - 1
        board = [[-1] * n for _ in range(n)]
        
        def dfs(x=0, y=0, step=0):
            board[x][y] = step
            if step == end_step:
                return True
            next_step = step + 1
            for dx, dy in MOVES:
                x1, y1 = x + dx, y + dy
                if 0 <= x1 < n and 0 <= y1 < n and board[x1][y1] == -1:
                    if dfs(x1, y1, next_step):
                        return True
            board[x][y] = -1
            return False
        
        if dfs():
            return board
        else:
            return [[-1]]
