class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int res=0;
        unordered_map<int,int> mpp; 
        for (int i=0;i<arr.size();i++){
            if (mpp.find(target-arr[i])!=mpp.end()){
                res+=mpp[target-arr[i]];
            }
            mpp[arr[i]]++;
        }
        return res;
    }
};

