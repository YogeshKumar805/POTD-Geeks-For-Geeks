class Solution:
    def minSoldiers(self, arr, k):
        import math
        key = []
        count = math.ceil(len(arr)/2)
        for i in arr:
            if i%k == 0:
                count-=1
            else:
                key.append(i)
        if count > 0:
            for i in range(len(key)):
                key[i] = key[i]%k
            key.sort(reverse=True)
            res = 0
            for i in range(count):
                res+= k-key[i]
            return res
        return 0

