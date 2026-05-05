class Solution:
    def sumXOR(self, arr):
        # code here
        total = 0
        n = len(arr)

        for bit in range(32):
            count0 = 0
            for val in arr:
                if val & (1 << bit) == 0:
                    count0 += 1
            
            count1 = n - count0
            total += count0 * count1 * (1 << bit)
        
        return total
