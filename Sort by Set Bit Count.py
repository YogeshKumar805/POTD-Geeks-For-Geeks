class Solution:
    def sortBySetBitCount(self, arr):
        def countBits(x):
            count = 0
            while x:
                x &= (x - 1)   
                count += 1
            return count
        
        arr.sort(key=countBits, reverse=True)
        return arr

