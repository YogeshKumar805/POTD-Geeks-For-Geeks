class Solution:
    def palindromePair(self, a: list) -> bool:
        """Return True if `a` contains two words which connect to form a palindrome."""
        # Build the set of words.
        words = set()
        for word in a:
            # Watch for palindromic copies.
            if word in words:
                return True
            words.add(word[::-1])
        # Iterate through prefixes and suffixes.
        for word in a:
            for j in range(1, len(word)):
                p, s = word[:j], word[j:]
                if p in words and s == s[::-1] or s in words and p == p[::-1]:
                    return True
        return False
