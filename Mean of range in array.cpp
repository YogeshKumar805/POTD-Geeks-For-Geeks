class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &q) {
        vector<int> ans;
        int n = arr.size();
        
        vector<int>pre(n + 1,0);
        pre[0] = arr[0];
        
        for(int i = 1;i < n;i++){
            pre[i] = pre[i - 1] + arr[i];
        }
        
        for(auto & it:q){
            int s = it[0];
            int e = it[1];
            
            int N = e - s + 1;
            // adding arr[s] to include s in this range since earlier it was 
            // substracted in --> (pre[e] - pre[s])
            int a = (pre[e] - pre[s] + arr[s]) / N;
            
            ans.push_back(a);
            
        }
        return ans;
    }
};
