// User function Template for C++
#define PIS pair<int,string>

class Solution {
  public:
    vector<vector<PIS>> dp;
    string split(string str, int st, int en)
    {
        string temp = "";
        for(int i=st;i<en;i++)
        temp += str[i];
        return temp;
    }
    PIS solve(vector<int>& arr, int st, int en, string str)
    {
        if(st==en)
        {
            string s(1, str[st - 1]);
            return {0,s};
        }
        
        if(dp[st][en].first!=-1)
        return dp[st][en];
        
        int res=INT_MAX;
        string res_str = "";
        
        for(int k=st;k<en;k++)
        {
            PIS l_res = solve(arr,st,k,str);
            PIS r_res = solve(arr, k+1, en, str);
            int val = (arr[st-1] * arr[k] * arr[en]);
            
            if(l_res.first + r_res.first + val < res)
            {
                res = l_res.first + r_res.first + val;
                res_str = "(" + l_res.second + r_res.second + ")";
            }
        }
        return dp[st][en]={res,res_str};
    }
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        dp=  vector<vector<PIS>>(n+1,vector<PIS>(n+1,{-1,""}));
        string temp = "";
        for(int i=0;i<n-1;i++)
        temp += ('A'+i);
        
        PIS res = solve(arr, 1, arr.size()-1,temp);
        return res.second;
    }
};
