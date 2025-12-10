class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long n=arr.size();
        long aSum=(n*(n+1))/2;
        long aSum2=(n*(n+1)*(2*n+1))/6;
        long obSum=0;
        long obSum2=0;
        for(long val:arr){
            obSum+=val;
            obSum2+=(val*val);
            
        }
        long val1=aSum-obSum;
        long val2=aSum2-obSum2;
        val2=val2/val1;
        int missing=(val1+val2)/2;
        int repeating =val2-missing;
        return {repeating,missing};
    }
};

