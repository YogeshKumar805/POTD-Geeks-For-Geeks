class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int org=n;
        int sum=0;
        while(n>0)
        {
            int dig=n%10;
            sum+=dig*dig*dig;
            n/=10;
        }
        return(sum==org)?"Yes":"No";
   }
};
