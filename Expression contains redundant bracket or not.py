class Solution():
    def checkRedundancy(self, s):
        # code here 
        stack = []
        for i in s :
            stack.append(i)
            if stack[-1] == ")" :
            
                if stack[-2] == "(" or stack[-3] == "(":
                    return True
                else :
                    while stack[-1] != "(":
                        stack.pop()
                    stack.pop()
        return False

