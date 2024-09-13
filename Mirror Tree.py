class Solution:
    #Function to convert a binary tree into its mirror tree.
    def mirror(self,root):
        def convert(root):
            if not root:
                return 
            temp=root.left
            root.left=root.right
            root.right=temp
            convert(root.left)
            convert(root.right)
        convert(root)
        return root
