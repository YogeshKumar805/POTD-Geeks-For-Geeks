class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int>mp;
        int sum=0, cnt=0;
        mp[0]=1;
        for(auto it : arr){
            sum+=it;
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            mp[sum]++;
       }
        return cnt;

    }
};
