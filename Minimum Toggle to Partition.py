class Solution:
    def minToggle(self, arr):
        ones = toggles = 0
        for num in arr:
            ones += num
            toggles = min(toggles + (1 - num), ones)
        return toggles
