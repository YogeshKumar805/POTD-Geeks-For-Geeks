class Solution:
    def subarrayXor(self, arr, k):
        # code here
        
        prefix_xor = 0
        count = 0
        freq = {}
        
        for num in arr:
            prefix_xor ^= num
            
            if prefix_xor == k:
                count += 1
                
            recq = prefix_xor ^ k
            if recq in freq:
                count += freq[recq]
            freq[prefix_xor] = freq.get(prefix_xor,0)+ 1
        return count

