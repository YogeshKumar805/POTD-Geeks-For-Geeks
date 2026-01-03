class Solution:
    def flatten(self, root):
        d = []
        def cc(h):
            if not h: return
            d.append(h.data)
            cc(h.bottom)
            cc(h.next)
        cc(root)
        d.sort()
        l = Node(-1)
        c = l
        for i in d:
            c.bottom = Node(i)
            c = c.bottom
        return l.bottom
