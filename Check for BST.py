class Solution:
    
    #Function to check whether a Binary Tree is BST or not.
    def isBST(self, root):
        #code here
        self.prev = float('-inf')
        def fun(root):
            if root == None:
                return True
            if fun(root.left) == False:
                return False
            if root.data <= self.prev:
                return False
            self.prev = root.data
            return fun(root.right)
        
        return fun(root)
