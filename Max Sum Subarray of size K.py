class Solution:
    def maxSubarraySum(self, arr, k):
        cont_sum = res = sum(arr[:k])
        for i in range(k,len(arr)):
            cont_sum = cont_sum - arr[i-k] + arr[i]
            res = max(cont_sum,res)
        return res
