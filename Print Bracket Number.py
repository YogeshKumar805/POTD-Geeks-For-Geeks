#User function Template for python3
class Solution:
	def bracketNumbers(self, str):
	    stack=[] 
	    c=0
	    ans=[]
	    for i in range(len(str)):
	        if(str[i]=='('):
	            c+=1 
	            ans.append(c)
	            stack.append(c)
	        elif(str[i]==')'):
	            ans.append(stack[-1]) 
	            stack.pop() 
	    return ans
