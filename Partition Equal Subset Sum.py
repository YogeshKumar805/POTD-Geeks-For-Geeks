class Solution:
    
    def f(self,arr,size,index,s,current,dp):
        if current ==(s/2):
            return 0
        if index >size -1 :
            return float('inf')
        ans=float('inf')
        #take cndn  
        if dp [index][current]!=-1:
            return dp[index][current]
        if (current +arr[index]) < s:
            ans = self.f(arr,size,index+1,s,current+arr[index],dp)
        if ans==0:
            return 0
        #not take cndn 
        ans=self.f(arr,size,index+1,s,current,dp)
        dp[index][current]= ans
        return dp[index][current]
    
    def equalPartition(self, arr):
        size =len (arr)
        s=0
        for i in range (size):
            s+=arr[i]
        dp = [[-1]*(s+1) for i in range (size)]    
        ans =self.f(arr,size,0,s,0,dp)
        if (ans==0):
            return True 
        return False
