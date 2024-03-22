#User function Template for python3

'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''


class Solution:
    def solve(self, root, diagonal, mp):
        if not root:
            return
        mp[diagonal] = mp.get(diagonal, 0) + root.data
        self.solve(root.left, diagonal + 1, mp)
        self.solve(root.right, diagonal, mp)
        
    def diagonalSum(self, root):
        mp = {}
        self.solve(root, 0, mp)
        ans = []
        for key, value in mp.items():
            ans.append(value)
        return ans
    
