from collections import Counter

class Solution:
    
    #Function is to check whether two strings are anagram of each other or not.
    def areAnagrams(self, s1, s2):
        c1 = Counter(s1)
        c2 = Counter(s2)
        return c1 == c2
