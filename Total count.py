class Solution:
    def totalCount(self, k, arr):
        ans = 0
        for i in range(len(arr)):
            a = (arr[i] + k - 1) // k
            ans += a
        return ans
