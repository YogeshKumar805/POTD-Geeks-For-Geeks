class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0;
        
        map<int, int> mp;
        int cur = 0;
        
        for(int i=0; i<n; ++i){
            
            cur ^= arr[i];
            
            if(cur==k){
                cnt++;
            }
            
            if(mp.find(cur^k)!=mp.end()){
                cnt += mp[cur^k];
            }
            mp[cur]++;
        }
        return cnt;
    }
};
