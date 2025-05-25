class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        
        bool ans = false;


        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]*arr[i]]++;
        }


        int k = *max_element(arr.begin(),arr.end());


        for(int i = 1 ; i <= k ; i++){
            for(int j = i + 1 ; j <= k ; j++){
                if(mp[i*i] && mp[j*j] && mp[(i*i)+(j*j)]){
                    ans = true;
                }
            }
        }
        return ans;
        
    }
};
