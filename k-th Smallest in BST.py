class Solution:
    def kthSmallest(self, root, k): 
        if root==None or self.count == k:
            return
        self.kthSmallest(root.left, k)
        self.count += 1
        if self.count  == k:
            self.result = root.data
        self.kthSmallest(root.right, k)    
        return self.result    
    count = 0
    result = -1   
