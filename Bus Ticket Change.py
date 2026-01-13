class Solution:
    def canServe(self, arr):
        n = len(arr)
        f,t = 0,0
        if arr[0] > 5:
            return False
        for i in range(n):
            if (arr[i] == 20):
                if(t and f):
                    f-=1
                    t-=1
                elif (f>=3):
                    f-=3
                else:
                    return False
            elif (arr[i] == 10):
                t+=1
                if(f):
                    f-=1
                else:
                    return False
            else:
                f+=1
             
        return True
