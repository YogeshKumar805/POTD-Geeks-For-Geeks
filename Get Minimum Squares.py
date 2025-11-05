import math

class Solution:
    def minSquares(self, n: int) -> int:
        if n < 0:
            return 0  # undefined for negative; adjust if needed
        if n == 0:
            return 0

        # helper: is x a perfect square?
        def is_square(x: int) -> bool:
            r = math.isqrt(x)
            return r * r == x

        # 1) perfect square?
        if is_square(n):
            return 1

        # 2) remove factors of 4
        while n % 4 == 0:
            n //= 4

        # 3) if n % 8 == 7 then by Legendre's theorem answer is 4
        if n % 8 == 7:
            return 4

        # 4) check if sum of two squares -> answer 2
        r = math.isqrt(n)
        for a in range(1, r + 1):
            if is_square(n - a * a):
                return 2

        # 5) otherwise it's 3 (by theory)
        return 3
