class Solution:
    def validParenthesis(self, s):
        
        # Function to check if string is valid
        def isValid(st):
            count = 0
            
            for ch in st:
                if ch == '(':
                    count += 1
                elif ch == ')':
                    count -= 1
                    
                    if count < 0:
                        return False
                        
            return count == 0
        
        
        res = []
        visited = set()
        queue = [s]
        visited.add(s)
        
        found = False
        
        while queue:
            curr = queue.pop(0)
            
            # If valid, add to result
            if isValid(curr):
                res.append(curr)
                found = True
            
            # If already found valid strings at this level,
            # do not generate next level
            if found:
                continue
            
            # Generate all possible strings
            for i in range(len(curr)):
                
                # Remove only parentheses
                if curr[i] not in '()':
                    continue
                
                nxt = curr[:i] + curr[i+1:]
                
                if nxt not in visited:
                    visited.add(nxt)
                    queue.append(nxt)
        
        return sorted(list(set(res)))
