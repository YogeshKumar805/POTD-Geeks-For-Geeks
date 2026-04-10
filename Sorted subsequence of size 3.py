class Solution:
    def find3Numbers(self, arr):
        l=len(arr)
        right_max=[-1]*l
        right_max[-1]=arr[-1]
        for i in range(l-2,-1,-1):
            right_max[i]=max(right_max[i+1],arr[i])
        left_min=arr[0]
        for i in range(1,l-1):
            if left_min<arr[i]<right_max[i+1]:
                return [left_min,arr[i],right_max[i+1]]
            left_min=min(left_min,arr[i])
        return []
