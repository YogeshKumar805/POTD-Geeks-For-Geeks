class Solution:
    def makeBeautiful(self, arr):
        
        def same_sign(a, b):
            return (a < 0 and b < 0) or (a >= 0 and b >= 0)

        stack = []

        for num in arr:
            if stack and not same_sign(stack[-1], num):
                stack.pop()
            else:
                stack.append(num)

        return stack
