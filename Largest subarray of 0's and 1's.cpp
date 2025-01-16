class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        int i=0,j=0;
        int ans = 0;
        map<int,int>mp;
        mp[0] = -1;
        int curr = 0;
        while(j<n){
            curr += arr[j];
            if(mp.find(curr)==mp.end()){
                mp[curr] = j;
                ans = max(ans,j-mp[curr]);
            }
            else{
                ans = max(ans,j-mp[curr]);
            }
            j++;
        }
        return ans;
    }
};
