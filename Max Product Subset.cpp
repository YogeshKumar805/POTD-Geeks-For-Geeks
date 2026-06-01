class Solution {
  public:
    virtual int findMaxProduct(vector<int>& arr){
      int mode=1e9+7;
      
      if(arr.size() == 1) return arr[0];
      
      long long prod=1LL;
      int zero=0, nonZero=0, negMaxi=INT_MIN;
      
      for(int x: arr){
        if(x){
          prod=(1LL*prod*x)%mode;
          nonZero++;
        }else{
          zero++;    
        }
        
        if(x<0) negMaxi=max(negMaxi, x);
        
      }
      
      if(nonZero==0) return 0;
      if(arr.size()==2 && zero==1 && prod<0) return 0;
      if(prod<0) prod=prod/(1LL*negMaxi);
      
      
      return (int)prod;
      
      
    }
};
