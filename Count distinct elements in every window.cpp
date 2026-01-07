class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int i=0;
        vector<int> res;
        unordered_map<int,int> mp;
        for(int j=0;j<arr.size();j++){
            mp[arr[j]]++;
            if(j-i+1==k){
               res.push_back(mp.size());
               mp[arr[i]]--;
               if(mp[arr[i]]==0)mp.erase(arr[i]);
               i++;
            }
        }
        return res;
    }
};
