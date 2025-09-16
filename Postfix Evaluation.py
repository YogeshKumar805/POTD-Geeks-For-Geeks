class Solution:
    def evaluatePostfix(self, arr):
        # code here
        stack = []
        for s in arr:
            if s == "+" or s=="-" or s=="*" or s== "/" or s == "^": # Check the operator and apply the operation if True
                b = stack.pop()
                a = stack.pop()
                if s == "+":
                    stack.append(a + b)
                elif s == "-":
                    stack.append(a - b)
                elif s == "*":
                    stack.append(a * b)
                elif s == "/":
                    stack.append(int(a // b)) # Fixed
                else: # s == "^" case
                    stack.append(int(a ** b)) 
            else:
                stack.append(int(s)) # Append the integer value to the stack
        return stack[-1]
