class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int mini=INT_MAX,i=0;
        
        for(auto it:arr){
            if(mini>it) mini=it;
        }
        
        while(i<arr.size()){
            if(arr[i]==mini) break;
            i++;
        }
        
        return i;
    }
};
