class Solution:
    def isPalindrome(self, head):
        temp=head
        arp=[]
        while temp.next != None:
            arp.append(temp.data)
            temp=temp.next
        arp=arp+[temp.data]
        if arp==arp[::-1]:
            return 1
        else:
            return
