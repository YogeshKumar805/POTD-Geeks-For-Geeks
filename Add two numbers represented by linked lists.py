class Solution:
    def addTwoLists(self, num1, num2):
        t1,t2=num1,num2
        x,y="",""
        while t1:
            x+=str(t1.data)
            t1 = t1.next
        while t2:
            y+=str(t2.data)
            t2 = t2.next
        n1,n2=int(x),int(y)
        res = n1+n2
        w = LinkedList()
        ans = []
        if res==0:
            ans = [0]
        while res>0:
            ans.append(res%10)
            res //= 10
        ans = ans[::-1]
        for i in ans:
            w.insert(i)
        return w.head
