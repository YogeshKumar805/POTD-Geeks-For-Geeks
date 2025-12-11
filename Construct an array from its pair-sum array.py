class Solution:
    def constructArr(self, arr):
        # code here
        from math import isqrt
        m = len(arr)
        if m == 0:
            return [1]
        if m == 1:
            return [1, arr[0] - 1]

        n = isqrt(m * 2) + 1
        a = (arr[0] + arr[1] - arr[n - 1]) // 2
        return [a] + [arr[i] - a for i in range(n - 1)]
