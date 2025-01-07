class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int low=0,high=arr.size()-1,ans=0;
      while(low<high)
      {
          if(arr[low]+arr[high]==target)
          {
              int prv=1,back=1;
              if(arr[low]==arr[high])
              {
                  int n=high-low+1;
                 int  sum=sum+(n*(n-1))/2;
                  ans=ans+sum;
                  break;
              }
              else
              {
             while(low<high && arr[low]==arr[low+1])
             {
                low++;
                prv++;
             }
             while(high>low && arr[high-1]==arr[high])
             {
                 back++;
                 high--;
             }
             int sum=prv*back;
             ans=ans+sum;
             high--;
             low++;
          }
          }
          
          else if(arr[low]+arr[high]>target)
          {
              high--;
          }
          else
          {
              low++;
          }
      }
          return ans;
    }
};
