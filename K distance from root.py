class Solution:
    def KDistance(self,root,k):        
        res = []
        
        def solve(root, dist):
            if not root:
                return 
            
            if dist == k:
                res.append(root.data)
                return 
            
            solve(root.left,  dist+1)
            solve(root.right, dist+1)
            
        solve(root,0)
        
        return res
