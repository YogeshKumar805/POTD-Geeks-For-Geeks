class Solution:
     def exitPoint(self, mat):
          # code here
          n = len(mat)
          m = len(mat[0])
          if n < 1 or m < 1:
               return []
          elif n == 1 and m == 1:
               return [0, 0]
          
          i = j = change = 0
          
          while (i>=0 and i<n) and (j>=0 and j<m):
               if mat[i][j] == 1:
                    change = (change+1) % 4
                    mat[i][j] = 0
               
               if change == 0:
                    j += 1
               elif change == 1:
                    i += 1
               elif change == 2:
                    j -= 1
               elif change == 3:
                    i -= 1

          if i == -1:
               i = 0
          elif i == n:
               i = n-1
          if j == -1:
               j = 0
          elif j == m:
               j = m-1
          return [i, j]
