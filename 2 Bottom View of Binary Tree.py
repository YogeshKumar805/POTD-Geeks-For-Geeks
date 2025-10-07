class Solution:
    def bottomView(self, root):
        # If the tree is empty
        if not root:
            return []

        # Dictionary to map horizontal distance → last (bottom-most) node data
        hd_node = {}

        # Queue for level order traversal (stores pair of node & horizontal distance)
        q = [(root, 0)]

        # Continue until all nodes are processed
        while q:
            node, hd = q.pop(0)  # Get front element

            # Always update node at each horizontal distance (bottom-most remains)
            hd_node[hd] = node.data

            # Add left child with hd - 1
            if node.left:
                q.append((node.left, hd - 1))

            # Add right child with hd + 1
            if node.right:
                q.append((node.right, hd + 1))

        # Sort horizontal distances and collect corresponding node values
        result = [hd_node[hd] for hd in sorted(hd_node)]

        return result

