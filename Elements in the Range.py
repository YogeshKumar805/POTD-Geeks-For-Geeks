class Solution:
    def checkElements(self, start, end, arr):
        s = set(arr)

        for num in range(start, end + 1):
            if num not in s:
                return False

        return True
