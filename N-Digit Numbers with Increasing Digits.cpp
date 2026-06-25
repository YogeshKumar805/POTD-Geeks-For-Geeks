class Solution {
  public:
    void solve(int n ,int num,vector<int>&ans, int prev)
    {
        if(n==0){
            ans.push_back(num/10);
            return;
        }
        
        for(int i=1;i<=9;i++){
            //i ko multiply tbhi krenge jab vo isk previous index se bada hoga
            if(i<=prev) continue;
            
            num+=(i*pow(10,n--));
            solve(n, num, ans, i);
            num-=(i*pow(10,++n));
            
        }
        
    }
    vector<int> increasingNumbers(int n) {
        vector<int>ans;
        int num = 0;
        int prev=0;//ye previous index pr kya value thi vo h
        
        if (n>9||n<1)return ans;
        if(n==1)return {0,1,2,3,4,5,6,7,8,9};
        else 
        solve(n, num, ans, prev);
        
     return ans;   
    }
};
