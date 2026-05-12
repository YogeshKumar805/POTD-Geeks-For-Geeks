import math

class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self._build(arr, 0, self.n - 1, 1)

    def _gcd(self, a, b):
        while b:
            a, b = b, a % b
        return a

    def _lcm(self, a, b):
        if a == 0 or b == 0:
            return max(a, b)
        return (a // self._gcd(a, b)) * b

    def _build(self, arr, l, r, idx):
        if l == r:
            self.tree[idx] = arr[l]
            return
        mid = (l + r) // 2
        self._build(arr, l, mid, 2 * idx)
        self._build(arr, mid + 1, r, 2 * idx + 1)
        self.tree[idx] = self._lcm(self.tree[2 * idx], self.tree[2 * idx + 1])

    def update(self, pos, val, l, r, idx):
        if l == r:
            self.tree[idx] = val
            return
        mid = (l + r) // 2
        if pos <= mid:
            self.update(pos, val, l, mid, 2 * idx)
        else:
            self.update(pos, val, mid + 1, r, 2 * idx + 1)
        self.tree[idx] = self._lcm(self.tree[2 * idx], self.tree[2 * idx + 1])

    def query(self, ql, qr, l, r, idx):
        if qr < l or ql > r:
            return 1
        if ql <= l and r <= qr:
            return self.tree[idx]
        mid = (l + r) // 2
        left = self.query(ql, qr, l, mid, 2 * idx)
        right = self.query(ql, qr, mid + 1, r, 2 * idx + 1)
        return self._lcm(left, right)

class Solution:
    def RangeLCMQuery(self, arr, queries):
        st = SegmentTree(arr)
        result = []
        n = len(arr)
        
        for q in queries:
            q_type = q[0]
            if q_type == 1:
                st.update(q[1], q[2], 0, n - 1, 1)
            else:
                result.append(st.query(q[1], q[2], 0, n - 1, 1))
        
        return result
