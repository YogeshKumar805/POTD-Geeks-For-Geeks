// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
          unordered_map<int,int>mp;
        int count=0;
        int sum=0;
        
        mp[0]=1;
        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            
            if(mp.find(sum-k)!=mp.end())
            {
                count+=mp[sum-k];
            }
            
            mp[sum]++;
        }
        
        return count;
    }
};
