class Solution:    
    def grayToBinary(self,n):
        bi=bin(n)#convert decimal to binary
        s=str(bi)#convert binary to string
        ans=""
        for i in range(2,len(s)):
            if i==2:
                ans+=s[i]
            else:
                ans+=str(int(ans[-1])^int(s[i])) #taking xor with msb 
        deci=int(ans,2)#convert binary str to decimal
        return deci
