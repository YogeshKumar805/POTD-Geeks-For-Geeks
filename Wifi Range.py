class Solution:
     def wifiRange(self, s, x):
          # code here
          w_r = []
          n = len(s)
          for w in range(n):
               if s[w] == '1':
                    w_r.append(w)
          
          if (len(w_r) < 1) or (w_r[0] > x) or (((n - 1) - w_r[-1]) > x):
               return False
          if len(w_r) == 1:
               return True
          for i in range(len(w_r) - 1):
               if (w_r[i+1] - w_r[i]) > (x*2)+1:
                    return False
          return True
