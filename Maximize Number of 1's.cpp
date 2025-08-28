class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int maxi=0;
        int zeroCount=0;
        int left=0;
        for(int right=0; right<arr.size(); right++){
            if(arr[right]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(arr[left]==0)
                zeroCount--;
                left++;
            }
            maxi= max(maxi, right- left+1);
        }
        return maxi;
    }
};
