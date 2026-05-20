class Solution:
    def isProduct(self, arr, target):
        # code here
        visited = set()
        
        for num in arr:
            if num == 0:
                if target == 0:
                    return True
                
            elif target/num in visited:
                return True
                
            visited.add(num)
            
        return False
