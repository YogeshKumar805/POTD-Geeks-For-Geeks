class Solution:
    def inorder(self, root, ans):
        # If the current node is None, return
        if root is None:
            return 
        # Recursively traverse the left subtree
        self.inorder(root.left, ans)
        # Add the current node's data to the answer list
        ans.append(root.data)
        # Recursively traverse the right subtree
        self.inorder(root.right, ans)

    def merge(self, root1, root2):
        # Initialize an empty list to hold the inorder traversal results
        ans = []
        # Perform inorder traversal on the first tree and store the results in ans
        self.inorder(root1, ans)
        # Perform inorder traversal on the second tree and store the results in ans
        self.inorder(root2, ans)
        # Sort the combined results from both trees
        ans.sort()
        # Return the sorted list
        return ans
