class Solution:
    def countSubset(self, arr, k):
        from collections import defaultdict
        reach = defaultdict(int)
        max_sum = min_sum = 0
        for a in arr:
            if a > 0:
                max_sum += a
            else:
                min_sum += a
        if not (min_sum <= k <= max_sum):
            return 0
        for a in arr:
            new_reach = reach.copy()
            for subsum, count in reach.items():
                if (sum_a := subsum + a) <= k:
                    new_reach[sum_a] += count
            new_reach[a] += 1
            reach = new_reach
        return reach[k]
