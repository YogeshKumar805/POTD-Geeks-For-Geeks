class Solution:
    def subarraySum(self, arr):
        n = len(arr)
        total_sum = 0
        for i in range(n):
            # element arr[i] contributes (i+1)*(n-i) times
            total_sum += arr[i] * (i + 1) * (n - i)
        return total_sum
