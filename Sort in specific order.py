class Solution:
    def sortIt(self, arr):
        odd=[]
        even=[]
        for i in arr:
            if i%2!=0:
                odd.append(i)
            else:
                even.append(i)
        odd.sort()
        odd=odd[::-1]
        even.sort()
        res=odd+even
        for i in range(len(res)):
            arr[i]=res[i]
        return arr

