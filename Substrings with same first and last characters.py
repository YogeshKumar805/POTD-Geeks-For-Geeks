from collections import Counter

class Solution:
    def countSubstring(self, s):
        freq = Counter(s)
        cnt = 0
        for ch in freq:
            f = freq[ch]
            cnt += (f * (f - 1)) // 2  # pairs (i < j) where s[i] == s[j]
            cnt += f  # each single character
        return cnt
