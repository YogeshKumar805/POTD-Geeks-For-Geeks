class Solution {
  public:
    bool canSplit(vector<int>& arr) 
    {
        long long sum=0;
        for (auto it: arr)
        {
            sum+=(long long)it;
        }
        if (sum%2!=0) return false;
        long long curSum=0;
        for (auto it: arr)
        {
            curSum+=it;
            if (curSum==(sum/2)) return true;
        }
        return false;
    }
};
