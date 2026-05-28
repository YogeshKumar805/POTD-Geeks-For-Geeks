# Structure of binary tree node
'''
class Node:
    def __init__(self, item):
        self.data = item
        self.left = None
        self.right = None
'''
class Solution:
    def assign_value(self,root,d1,index):
        if index not in d1:
            d1[index]=[]
        d1[index].append(root.data)
        if root.left:
            self.assign_value(root.left,d1,index-1)
        if root.right:
            self.assign_value(root.right,d1,index+1)
    def verticalSum(self, root):
        d1={}
        self.assign_value(root,d1,0)
        sorted_ans=sorted(d1)
        ans=[]
        for i in sorted_ans:
            ans.append(sum(d1[i]))
        return ans   

