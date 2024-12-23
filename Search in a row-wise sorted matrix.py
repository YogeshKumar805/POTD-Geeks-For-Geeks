class Solution:
    def searchRowMatrix(self, matrix, x):
        a = len(matrix)
        b = len(matrix[0]) if a > 0 else 0
        
        for i in range(a):
            for j in range(b):
                if matrix[i][j] == x:
                    return True
        return False
