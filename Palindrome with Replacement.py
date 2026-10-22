class Solution:
    def minimumSum(self, s: str) -> int:
        n = len(s)
        m = (n + 1) // 2

        prev = -1
        res = 0

        for i in range(m):
            left = s[i]
            right = s[n - 1 - i]

            if left != '?' and right != '?' and left != right:
                return -1

            ch = left if left != '?' else right

            if ch != '?':
                curr = ord(ch)

                if prev != -1:
                    res += abs(curr - prev)

                prev = curr

        return 2 * res
        
