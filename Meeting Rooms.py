class Solution:
    def canAttend(self, arr):
        # Code Here
        arr.sort()
        
        prev = arr[0]
        
        for i,j in arr[1:]:
            if prev[1] > i:
                return False
            prev = [i,j]
        return True
