class Solution:
    #Function to check if the linked list has a loop.
    def detectLoop(self, head):
        #code here
        curr = head 
        s=set()
        while curr:
            if curr in s:
                return True
                break
            s.add(curr)
            curr=curr.next
        return False    
