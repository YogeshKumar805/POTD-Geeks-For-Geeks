class Solution:
    #Function to find the minimum element in the given BST.
    def minValue(self, root):
        ##Your code here
        return self.minValue(root.left) if root.left !=None else root.data
