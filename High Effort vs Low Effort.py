class Solution:
    def maxTask(self, h: list[int], l: list[int]) -> int:
        n = len(h)
        past, prev = 0, 0
        for idx in range(n):
            prev, past = max(l[idx] + prev, h[idx] + past), prev
        
        return prev
