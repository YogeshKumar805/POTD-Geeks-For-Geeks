class Solution():
    def cloneHelper(self, node):
        if self.d.get(node, None):
            return self.d.get(node)

        nnode = Node(node.val)
        self.d[node] = nnode
        
        for i in node.neighbors:
            nnode.neighbors.append(self.cloneHelper(i))

        return nnode
        
    def cloneGraph(self, node):
        self.d = {}
        nnode = self.cloneHelper(node)
        return nnode
