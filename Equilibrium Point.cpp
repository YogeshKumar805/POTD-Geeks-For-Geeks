class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
       
       int sum1=accumulate(arr.begin(),arr.end(),0);
       int sum2=0;
       for(int i=0;i<arr.size();i++){
           sum1-=arr[i];
           if(sum1==sum2)
           return i;
           sum2+=arr[i];
       }
       return -1;
    }
};

