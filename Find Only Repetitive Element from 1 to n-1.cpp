class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int ans=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto it:mp)
        {
            if(it.second>1)
            {
                ans=it.first;
                break;
            }
        }
        
        return ans;
        
    }
};
