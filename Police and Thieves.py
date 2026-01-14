class Solution:
    def catchThieves(self, arr, k):
        n = len(arr)
        i = j = cnt = 0
        
        while i < n and j < n:
            while i < n and arr[i] != 'P':
                i += 1
            while j < n and arr[j] != 'T':
                j += 1
                
            if i < n and j < n:
                if abs(i-j) <= k:
                    cnt += 1
                    i += 1
                    j += 1
                elif i < j:
                    i += 1
                else:
                    j += 1
        return cnt
