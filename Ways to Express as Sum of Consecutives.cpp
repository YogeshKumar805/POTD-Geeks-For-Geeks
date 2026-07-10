class Solution {
  public:
    virtual int svc(int n, int i){
      if(n<=0) return 0;
      
      return ((n-i)%i==0) + svc(n-i, i+1);
    }
    virtual int getCount(int n){
      return svc(n, 1) - 1;
    }
};
