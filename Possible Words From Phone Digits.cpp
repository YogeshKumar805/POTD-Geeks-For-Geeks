class Solution {
  public:
    void solve(int idx,vector<int> &arr, vector<string> &ans,string &sol,map<int, string> &mp)
    {
        if(idx == arr.size())
        {
            ans.push_back(sol);
            return;
        }
        if(arr[idx] == 1 or arr[idx] == 0)
        {
            solve(idx+1,arr,ans,sol,mp);
            return;
        }
        
        for(int i = 0; i<mp[arr[idx]].size();i++){
            sol.push_back(mp[arr[idx]][i]);
            solve(idx+1,arr,ans,sol,mp);
            sol.pop_back();
        }
        return;
    }
    vector<string> possibleWords(vector<int> &arr) {
        map<int, string> mp=
        {
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"}
        };
        string sol;
        vector<string> ans;
        solve(0, arr, ans, sol,mp);
        
        return ans;
    }
};
