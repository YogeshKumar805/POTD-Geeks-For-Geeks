class Solution:
    def maxOfMins(self, arr):
        mins = [1] * len(arr)
        
        stack = []
        for i, v in enumerate(arr):
            while stack and arr[stack[-1]] > v:
                pop = stack.pop()
                mins[pop] += i - pop - 1
            
            if stack:
                mins[i] += i - stack[-1] - 1
            else:
                mins[i] += i
            
            stack.append(i)

        tail = stack.pop()
        while stack:
            pop = stack.pop()
            mins[pop] += tail - pop
            

        res = [0] * len(arr)
        for i, v in enumerate(mins):
            res[v - 1] = max(res[v - 1], arr[i])

        maxi = 0
        for i in range(len(arr)-1, -1, -1):
            maxi = max(maxi, res[i])
            res[i] = maxi
            
        return res
