class Solution:
    def countFreq(self, arr, target):
        count = 0
        for num in arr:
            if num == target:
                count += 1
        return count
