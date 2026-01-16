class Solution:
    def minMen(self, arr):
        #code here 
        stack = []
        for i in range(len(arr)):
            left = max(0, i - arr[i])
            right = min(len(arr) - 1, i + arr[i])
            while stack and stack[-1][0] >= left and stack[-1][1] <= right:
                stack.pop()
            if len(stack) == 0:
                stack.append([left, right])
            elif stack[-1][1] < right:
                stack.append([max(stack[-1][1] + 1, left), right])
        if stack[0][0] == 0 and stack[-1][1] == len(arr) - 1:
            for i in range(1, len(stack)):
                if stack[i][0] - stack[i - 1][1] > 1:
                    return -1
            return len(stack)
        return -1
