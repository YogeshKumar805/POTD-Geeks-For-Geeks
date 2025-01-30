class Solution:
    def isSafe(self, board, row, col, n):
        # Check for queen in the same column
        for i in range(row):
            if board[i] == col:
                return False
        # Check left diagonal
        for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
            if board[i] == j:
                return False
        # Check right diagonal
        for i, j in zip(range(row - 1, -1, -1), range(col + 1, n)):
            if board[i] == j:
                return False
        return True 
        
    def solveQueen(self,board,row,n,ans):
        # base condition
        if row==n:
            ans.append([col + 1 for col in board])
            return
        for j in range(n):
            if self.isSafe(board,row,j,n):
                board[row] = j  # Place queen
                self.solveQueen(board,row+1,n,ans)
                board[row] = -1  # Backtrack
                

    def nQueen(self, n):
        board = [-1] * n  # Track queen positions in each row
        ans=[]
        self.solveQueen(board,0,n,ans)
        return ans 
        

