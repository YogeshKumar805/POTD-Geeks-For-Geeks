class Solution:
    def reducePairs(self, arr):
        stack = []

        for num in arr:
            curr = num

            while stack and stack[-1] * curr < 0:  # opposite signs
                if abs(stack[-1]) > abs(curr):
                    curr = stack[-1]
                    stack.pop()
                elif abs(stack[-1]) < abs(curr):
                    stack.pop()
                else:  # equal absolute values
                    stack.pop()
                    curr = None
                    break

            if curr is not None:
                stack.append(curr)

        return stack
