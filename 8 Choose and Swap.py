class Solution:
    def chooseSwap(self, s):
        # code here
        n=len(s)
        dic={}
        for i in range(n):
            dic[s[i]]=i
        change_from=''
        change_to=''
        check=set()
        for i in range(n):
            el=s[i]
            boo=False
            for j in range(ord('a'),ord(el)):
                alpha=chr(j)
                if alpha in dic and dic[alpha]>i and alpha not in check:
                    change_from=s[i]
                    change_to=alpha
                    boo=True
                    break
            check.add(el)
            if boo:
                break
        if not change_from:
            return s
        ans=''
        for el in s:
            if el==change_from:
                ans+=change_to
            elif el==change_to:
                ans+=change_from
            else:
                ans+=el
        return ans
