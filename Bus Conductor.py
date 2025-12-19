class Solution:
    def findMoves(self, chairs, passengers):
        # code here
        count = 0
        
        chairs.sort()
        passengers.sort()
        
        for i,j in zip(chairs, passengers):
            count += abs(i-j)
        
        return count
