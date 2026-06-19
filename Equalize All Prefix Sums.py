class Solution:
    def optimalArray(self, arr):
        n = len(arr)

        # Prefix sums
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + arr[i]

        ans = []

        for i in range(n):
            mid = i // 2
            median = arr[mid]

            left_cost = median * (mid + 1) - prefix[mid + 1]
            right_cost = (prefix[i + 1] - prefix[mid + 1]) - median * (i - mid)

            ans.append(left_cost + right_cost)

        return ans
