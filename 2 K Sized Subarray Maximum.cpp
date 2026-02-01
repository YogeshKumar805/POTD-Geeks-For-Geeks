class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>a;
        int n=arr.size();
       
        priority_queue<pair<int,int>>q;
        
        for(int r=0;r<k;r++){
            q.push({arr[r],r});
        }
        a.push_back(q.top().first);
        
        for(int r=k;r<n;r++){
            
             q.push({arr[r],r});
             while (!q.empty() && q.top().second <= r - k) {
                q.pop();
            }
            
            a.push_back(q.top().first);
        }
        return a;
        
    }
};
