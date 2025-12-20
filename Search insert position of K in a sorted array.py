class Solution:
    def searchInsertK(self, arr, k):
        # code here
        import numpy as np
        return np.searchsorted(arr, k)
