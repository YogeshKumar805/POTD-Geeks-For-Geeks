class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int r = 1; // help us to determine starting new subarray
        int count = 1; // size of curr working subarray
        int e = 0; // store last equals elements
        int ans = 1; // store length of max subarray
        int n = arr.size();
        
        for(int i=1;i<n;i++){
            
            if(arr[i-1]==arr[i]){
                count++;
                e++;
        
            }
            else if(arr[i]<arr[i-1]){
                count++;
                e=0;
                r=0;
            }
            else{
                
                if(r==0){
                    r=1;
                    count = e+2;
                    e=0;
                    
                }
                else{
                    count++;
                    e=0;
                }
                
            }
            
            ans = max(ans,count);
            
        }
        
        return ans;
        
    }
};
