class Solution:
    def uniquePerms(self, arr):
        arr.sort()
        n = len(arr)
        res = []
        used = [False]*n

        def backtrack(path):
            if len(path) == n:
                res.append(path[:])
                return
            for i in range(n):
                if used[i]: 
                    continue
                if i > 0 and arr[i] == arr[i-1] and not used[i-1]:
                    continue
                used[i] = True
                path.append(arr[i])
                backtrack(path)
                path.pop()
                used[i] = False

        backtrack([])
        return res
