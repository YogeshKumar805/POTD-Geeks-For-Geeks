class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int ans = 0;
         unordered_map<int,int> mp;
         int cntD = 0;
         int idxD=0;
         int j = 0;
         int i =0;
         int n = arr.size();
         
         while(j < n){
             if(mp[arr[j]]++ == 0){
                 cntD++;
                 if(cntD > k){
                     ans += ((j-i)*(j-i + 1))/2 ;
                    //  cout<<ans<<" ";
                     while(i < j ){
                         if(--mp[arr[i]] == 0) {
                             cntD--;
                             i++;
                             break;
                         }
                         i++;
                     }
                      ans -= ((j-i)*(j-i + 1))/2 ;
                    //  cout<<ans<<" ";
                 }
             }
             j++;
         }
             ans += ((j-i)*(j-i + 1))/2 ;
         return ans;
    }
};
