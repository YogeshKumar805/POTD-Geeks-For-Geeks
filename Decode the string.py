from collections import deque
class Solution:
    def decodedString(self, s):
        # code here
        stack=[]
        num=[]
        op=""
        j=0
        while j<len(s):
            ch=s[j]
            if ch.isdigit():
                if j>0 and s[j-1].isdigit():
                    prev+=ch
                    num.pop()
                    num.append(prev)
                else:
                    num.append(ch)
                    prev=ch
                    
            elif ch=='[' or 'a'<=ch<="z":
                stack.append(ch)
                
            else:
                temp=deque([])
                di=int(num.pop()) if num else 1
                while stack and stack[-1]!='[':
                    temp.appendleft(stack.pop())
                if stack:
                    stack.pop()
                stack.append(("".join(temp))*di)
            j+=1
        return "".join(stack)
            
