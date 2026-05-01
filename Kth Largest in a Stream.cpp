class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            while(pq.size()>k){
                pq.pop();
            }
            ans.push_back(pq.size()==k?pq.top():-1);
        }
        return ans;
    }
};
