class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Map every element as +1/ -1 
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<= k){
                arr[i]= -1;
            }
            else{
                arr[i]= 1;
            }
        }
        unordered_map<int, int> mp;
        int sum= 0;
        int maxLen= 0;
        
        for(int i=0;i<n;i++){
           // if sum> 0 then it will longest subarray
           sum+= arr[i];
           if(sum> 0){
               maxLen= i+1;
           }
           // if not find the previous index with sum= sum -1 
           //then Subarray sum will be 1
           else{
               if(mp.find(sum-1)!= mp.end()){
                   maxLen= max(maxLen, i- mp[sum-1]);
               }
           }
           // Update new index for sum only if it is not present earlier
           // Because we want largest separation so oldest is porefered
           if(!mp.count(sum)) mp[sum]= i;
        }
        return maxLen;
    }
};
