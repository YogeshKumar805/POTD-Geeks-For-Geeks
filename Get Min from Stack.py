class Solution:

    def __init__(self):
        # code here
        self.s=[]
        self.min_s=[]
        
    # Add an element to the top of Stack
    def push(self, x):
        # code here
        self.s.append(x)
        if not self.min_s or x <= self.min_s[-1]:
            self.min_s.append(x)
        

    # Remove the top element from the Stack
    def pop(self):
        # code here
        if self.s:
            if self.s[-1] == self.min_s[-1]:  
                self.min_s.pop()  
            self.s.pop()

    # Returns top element of Stack
    def peek(self):
        # code here
        if self.s:
            return self.s[-1]
        return -1

    # Finds minimum element of Stack
    def getMin(self):
        # code here
        if self.min_s:
            return self.min_s[-1]
        return -1
