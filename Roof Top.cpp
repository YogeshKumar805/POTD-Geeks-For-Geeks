class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        
        int cnt=0;
        
        bool flag=true;
        
        int maxi=0;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1] && flag){
                cnt++;
            }
            else{
                flag=true;
                cnt=0;
            }
            maxi=max(maxi,cnt);
        }
        
        return maxi;
    }
};
