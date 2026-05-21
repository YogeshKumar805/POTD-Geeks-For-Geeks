class Solution:
    def isBitSet(self, n):
        # 0 does not have all bits set
        if n == 0:
            return False
        
        # Check if all bits are set
        return (n & (n + 1)) == 0
