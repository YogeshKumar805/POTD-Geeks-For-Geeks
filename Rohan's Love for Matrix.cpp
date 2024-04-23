class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod=1e9+7;
        int prev=1;
        int curr=1;
        int temp=0;
        
        for(int i=0;i<n-1;i++){
            temp=curr;
            curr=(prev+curr)%mod;
            prev=temp;
        }
        
        return prev%mod;
    }
};
