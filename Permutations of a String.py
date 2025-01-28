#User function Template for python3

from itertools import permutations

class Solution:
    def findPermutation(self, s):
        # Code here
        perm_set = set(permutations(s))
        return sorted([''.join(p) for p in perm_set])
