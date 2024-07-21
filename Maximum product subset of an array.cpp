class Solution {
  public:
    const long long MOD = 1e9+7; 
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long prod = 1;
        long long maxi = -1e9;
        
        int cntneg=0,cntpos=0;
        
        for(auto &x : arr){
            if(x != 0) prod = ((prod%MOD)*x)%MOD;
            if(x < 0) {
                maxi = max(maxi,(long long)x);
                cntneg++;
            }
            if(x > 0) cntpos++;
        }   
        
        if(cntneg == 1 and cntpos==0){
            if(arr.size()==1) return prod;
            if(arr.size()>=1) return 0; 
        }
        
        if(prod < 0) prod = prod/maxi;
        
        return prod;
    }
};
