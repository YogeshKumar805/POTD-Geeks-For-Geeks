class Solution:
     def diagView(self, mat): 
          # code here 
          n, m = len(mat), len(mat[0])
          ans = []

          for x in range(m):
               row = 0
               col = x
               ans.append(mat[row][col])
               while row+1 < n and col-1 >= 0:
                    row += 1
                    col -= 1
                    ans.append(mat[row][col])
          
          for y in range(1, n):
               row = y
               col = m-1
               ans.append(mat[row][col])
               while row+1 < n and col-1 >= 0:
                    row += 1
                    col -= 1
                    ans.append(mat[row][col])
          
          return ans
