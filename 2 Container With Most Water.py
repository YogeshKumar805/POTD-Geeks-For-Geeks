class Solution:
    def maxWater(self, arr):
        # code here
        left, right, max_area = 0, len(arr) - 1, 0
        while left < right:
            if arr[left] < arr[right]:
                area = arr[left] * (right - left)
                left += 1
            else:
                area = arr[right] * (right - left)
                right -= 1
            if area > max_area:
                max_area = area
        return max_area
