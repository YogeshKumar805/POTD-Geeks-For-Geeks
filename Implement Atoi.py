class Solution:
     def myAtoi(self, s):
          # code here
          s = s.lstrip()
          digits = '0123456789'
          sign = '-+'
          res = ''
          sgn = ''

          for ch in s:
               # print(ch)
               if ch not in digits and ch not in sign:
                    break
               elif ch in digits and ch not in sign:
                    res += ch
               elif ch not in digits and ch in sign:
                    sgn = ch
               
          if not res:
               num = 0
          
          if sgn == '-' and res:
               num = -int(res)
               if num < (2 ** 31) * -1:
                    return (2 ** 31) * -1
               
          elif sgn == '+' or not sgn and res:
               num = +int(res)
               if num > (2 ** 31) - 1:
                    return (2 ** 31) -1
          
          return num
