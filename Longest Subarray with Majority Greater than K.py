class Solution:
    def longestSubarray(self, arr, k):
        n = len(arr)
        
        # Transform array
        for i in range(n):
            if arr[i] > k:
                arr[i] = 1
            else:
                arr[i] = -1
        
        prefix = 0
        first_occurrence = {}
        max_len = 0
        
        for i in range(n):
            prefix += arr[i]

            if prefix > 0:
                max_len = i + 1
            
            if prefix not in first_occurrence:
                first_occurrence[prefix] = i
            
            if (prefix - 1) in first_occurrence:
                max_len = max(max_len, i - first_occurrence[prefix - 1])
        
        return max_len
