class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        
        //Kadane's Algorithm
        int currSum = 0;
        int maxSum = -1;
        
        for( char ch:s) {
            if(ch == '0')
                currSum++;
            
            else 
                currSum--;
            
            
            maxSum = max(currSum,maxSum);
             if(currSum < 0)
            currSum = 0;
        }
        return maxSum;
    }
};

..... see less

