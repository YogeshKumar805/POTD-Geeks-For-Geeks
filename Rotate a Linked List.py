class Solution:
    
    #Function to rotate a linked list.
    def rotate(self, head, k):
        l = []
        while head:
            l.append(head.data)
            head = head.next
        k = k%len(l)
        new = l[k:]+l[:k]
        new_head = Node(new[0])
        current = new_head
        for i in range(1,len(new)):
            temp = Node(new[i])
            current.next = temp
            current = current.next
        return new_head
