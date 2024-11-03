class Solution:
    def isLengthEven(self, head):
        # Traverse two nodes at a time
        while head and head.next:
            head = head.next.next
        # If head is None, then the length is even
        return head is None
