class Solution:
    def minParentheses(self, s):
        stack=[]
        for i in s:
            if len(stack)==0:
                stack.append(i)
            elif (stack[-1]=="(" and i==")")or(stack[-1]=="{" and i=="}")or(stack[-1]=="[" and i=="]"):
                stack.pop()
            else:
                stack.append(i)                
        return len(stack)
