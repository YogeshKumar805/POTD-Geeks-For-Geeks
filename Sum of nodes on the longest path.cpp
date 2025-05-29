class Solution:
    def sumOfLongRootToLeafPath(self, root):
        #sam
        all_path = []
        path = []
        self.solve(root,all_path,path)
        maxi = 0
        for i in range(len(all_path)):
            n = len(all_path[i])
            if maxi<n:
                maxi = n
                idx = i
        max_sm = 0
        for i in range(len(all_path)):
            n = len(all_path[i])
            if n==maxi:
                sm = sum(all_path[i])
                max_sm = max(max_sm,sm)
        return max_sm
    
    def solve(self,root,all_path,path):
        if not root:
            return
        path.append(root.data)
        
        if not root.left and not root.right:
            all_path.append(path[:])

        self.solve(root.left,all_path,path)
        self.solve(root.right,all_path,path)
        path.pop()
