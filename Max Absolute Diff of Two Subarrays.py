class Solution:
    def maxDiffSubArrays(self, arr):
        n = len(arr)

        leftMax = [0] * n
        leftMin = [0] * n
        rightMax = [0] * n
        rightMin = [0] * n

        # Left maximum
        curr = best = arr[0]
        leftMax[0] = best
        for i in range(1, n):
            curr = max(arr[i], curr + arr[i])
            best = max(best, curr)
            leftMax[i] = best

        # Left minimum
        curr = best = arr[0]
        leftMin[0] = best
        for i in range(1, n):
            curr = min(arr[i], curr + arr[i])
            best = min(best, curr)
            leftMin[i] = best

        # Right maximum
        curr = best = arr[-1]
        rightMax[-1] = best
        for i in range(n - 2, -1, -1):
            curr = max(arr[i], curr + arr[i])
            best = max(best, curr)
            rightMax[i] = best

        # Right minimum
        curr = best = arr[-1]
        rightMin[-1] = best
        for i in range(n - 2, -1, -1):
            curr = min(arr[i], curr + arr[i])
            best = min(best, curr)
            rightMin[i] = best

        ans = 0
        for i in range(n - 1):
            ans = max(ans,
                      abs(leftMax[i] - rightMin[i + 1]),
                      abs(leftMin[i] - rightMax[i + 1]))

        return ans
