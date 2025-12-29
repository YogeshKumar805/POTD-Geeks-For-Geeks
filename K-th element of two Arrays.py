class Solution:
    def kthElement(self, a, b, k):
        # code here
        if len(a) > len(b):
            return self.kthElement( b, a, k)
        n, m = len(a), len(b)
        low = max(0, k - m)
        high = min(k, n)
    
        while low <= high:
            cutA = (low + high) // 2
            cutB = k - cutA
    
            leftA = a[cutA - 1] if cutA > 0 else float('-inf')
            leftB = b[cutB - 1] if cutB > 0 else float('-inf')
            rightA = a[cutA] if cutA < n else float('inf')
            rightB = b[cutB] if cutB < m else float('inf')
    
            if leftA <= rightB and leftB <= rightA:
                return max(leftA, leftB)
            elif leftA > rightB:
                high = cutA - 1
            else:
                low = cutA + 1
    
        return -1
