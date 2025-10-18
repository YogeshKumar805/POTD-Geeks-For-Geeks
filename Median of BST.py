class Solution:
    def findMedian(self, root):
        def inorder(node):
            if not node:
                return []
            return inorder(node.left)+ [node.data]+inorder(node.right)
        lst=inorder(root)
        if len(lst)%2==0:
            return lst[len(lst)//2-1]
        else:
            return lst[(len(lst)+1)//2-1] 
