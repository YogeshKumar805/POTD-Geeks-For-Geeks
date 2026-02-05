class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int zero =0;
        int s =0,f=0;
        int ans =0, n = arr.size();
        while(f<n){
            if(arr[f] == 0) zero++;
            
            if(zero  == k +1){
                while(s<=f){
                    if(arr[s++] == 0) break;
                }
                zero--;
            }
            ans = max(ans,f-s+1);
            f++;
        }
        return ans;
        
    }
};

