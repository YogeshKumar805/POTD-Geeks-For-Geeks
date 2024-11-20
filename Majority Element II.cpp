class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
     map<int,int>freq;
       vector<int>ans;
       for(auto i:arr)
       {
           freq[i]++;
       }
        for(auto i:freq)
       {
           if(i.second>arr.size()/3)ans.push_back(i.first);
       }
       return ans;
    }
};
